import sys
import random
from BitVector import *
from math import gcd

class PrimeGenerator(object):                                              

    def __init__( self, **kwargs ):                                          
        bits = debug = None                                                 
        if 'bits' in kwargs  :     bits = kwargs.pop('bits')                
        if 'debug' in kwargs :     debug = kwargs.pop('debug')              
        self.bits            =     bits                                     
        self.debug           =     debug                                   
        self._largest        =     (1 << bits) - 1                          

    def set_initial_candidate(self):                                         
        candidate = random.getrandbits( self.bits )                        
        if candidate & 1 == 0: candidate += 1                               
        candidate |= (1 << self.bits-1)                                    
        candidate |= (2 << self.bits-3)                                     
        self.candidate = candidate                                        

    def set_probes(self):                                                   
        self.probes = [2,3,5,7,11,13,17]                                    

    def test_candidate_for_prime(self):                                      
        p = self.candidate                                                  
        if p == 1: return 0                                               
        if p in self.probes:                                                
            self.probability_of_prime = 1                                   
            return 1                                                     
        if any([p % a == 0 for a in self.probes]): return 0                
        k, q = 0, self.candidate-1                                          
        while not q&1:                                                      
            q >>= 1                                                          
            k += 1                                                          
        if self.debug: print("q = %d  k = %d" % (q,k))                       
        for a in self.probes:                                                
            a_raised_to_q = pow(a, q, p)                                     
            if a_raised_to_q == 1 or a_raised_to_q == p-1: continue          
            a_raised_to_jq = a_raised_to_q                                   
            primeflag = 0                                                    
            for j in range(k-1):                                             
                a_raised_to_jq = pow(a_raised_to_jq, 2, p)                   
                if a_raised_to_jq == p-1:                                    
                    primeflag = 1                                            
                    break                                                    
            if not primeflag: return 0                                       
        self.probability_of_prime = 1 - 1.0/(4 ** len(self.probes))          
        return self.probability_of_prime                                     

    def findPrime(self):                                                     
        self.set_initial_candidate()                                       
        if self.debug:  print("    candidate is: %d" % self.candidate)       
        self.set_probes()                                                    
        if self.debug:  print("    The probes are: %s" % str(self.probes))   
        max_reached = 0                                                      
        while 1:                                                             
            if self.test_candidate_for_prime():                              
                if self.debug:                                               
                    print("Prime number: %d with probability %f\n" %       
                          (self.candidate, self.probability_of_prime) )      
                break                                                        
            else:                                                            
                if max_reached:                                              
                    self.candidate -= 2                                      
                elif self.candidate >= self._largest - 2:                    
                    max_reached = 1                                          
                    self.candidate -= 2                                      
                else:                                                        
                    self.candidate += 2                                      
                if self.debug:                                               
                    print("    candidate is: %d" % self.candidate)           
        return self.candidate  
    
class RSA():
    def __init__ (self, e) -> None :
        self.e = e
        self.n = []
        self.d = None
        self.p = []
        self.q = []
    
    def create_prime(self, bit_w):
        while True:
            generator = PrimeGenerator(bits = bit_w)                 
            prime = generator.findPrime()
            if gcd(self.e, prime - 1) == 1:
                return prime
    
    def solve_pRoot(self, p, x): 
        u = 1
        while u ** p <= x: u *= 2

        l = u // 2
        while l < u:
            mid = (l + u) // 2
            mid_pth = mid ** p
            if l < mid and mid_pth < x:
                l = mid
            elif u > mid and mid_pth > x:
                u = mid
            else:
                return mid
        return mid + 1

    def encrypt_3(self, plaintext:str, moduli :str) -> None :
        bit_width = 128
        for x in range(6):
            prime = self.create_prime(bit_width)
            if x % 2 == 0:
                self.p.append(prime)
            else:
                self.q.append(prime)   

        for x in range(len(self.p)):
            n = self.p[x] * self.q[x]
            self.n.append(n)

        bv = BitVector(filename = plaintext)

        FILE = open(moduli, 'w')
        for n in self.n:
            FILE.write(f"{n}\n")

        FILE_1 = open(sys.argv[3], 'w') 
        FILE_2 = open(sys.argv[4], 'w')  
        FILE_3 = open(sys.argv[5], 'w') 

        while bv.more_to_read:
            bitvec = bv.read_bits_from_file(128)
            if len(bitvec) > 0:
                if len(bitvec) != 128:
                    bitvec.pad_from_right(128 - len(bitvec))
                bitvec.pad_from_left(128)
                cipher1_int = pow(bitvec.int_val(), self.e, self.n[0])
                cipher2_int = pow(bitvec.int_val(), self.e, self.n[1])
                cipher3_int = pow(bitvec.int_val(), self.e, self.n[2])
                cipher1 = BitVector(intVal=cipher1_int, size=256)
                cipher2 = BitVector(intVal=cipher2_int, size=256)
                cipher3 = BitVector(intVal=cipher3_int, size=256)
                FILE_1.write(cipher1.get_bitvector_in_hex())
                FILE_2.write(cipher2.get_bitvector_in_hex())
                FILE_3.write(cipher3.get_bitvector_in_hex())

    
    def break_3(self, ciphertext_1 :str, ciphertext_2 :str, ciphertext_3 :str, recovered_plaintext:str) -> None :
        FILE_1 = open(ciphertext_1, 'r') 
        a_1 = BitVector(hexstring = FILE_1.read())
        FILE_2 = open(ciphertext_2, 'r') 
        a_2 = BitVector(hexstring = FILE_2.read())
        FILE_3 = open(ciphertext_3, 'r') 
        a_3 = BitVector(hexstring = FILE_3.read())
        
        with open(sys.argv[5], 'r') as file:
            first_lines = file.readlines()[:3]
            n_list = [int(line.strip()) for line in first_lines]

        bv_n1 = BitVector(intVal = n_list[0])
        bv_n2 = BitVector(intVal = n_list[1])
        bv_n3 = BitVector(intVal = n_list[2])
        
        mod_N = n_list[0] * n_list[1] * n_list[2]

        M = [n_list[1] * n_list[2], n_list[0] * n_list[2], n_list[0] * n_list[1]]
        
        bv_M1 = BitVector(intVal = M[0])
        bv_M2 = BitVector(intVal = M[1])
        bv_M3 = BitVector(intVal = M[2])

        c1 = bv_M1.int_val() * (bv_M1.multiplicative_inverse(bv_n1)).int_val()
        c2 = bv_M2.int_val() * (bv_M2.multiplicative_inverse(bv_n2)).int_val()
        c3 = bv_M3.int_val() * (bv_M3.multiplicative_inverse(bv_n3)).int_val()
        
        with open(recovered_plaintext, 'w') as file:
            for i in range(len(a_1) // 256):
                
                bitvec_1 = a_1[i*256: (i + 1) * 256]
                bitvec_2 = a_2[i*256: (i + 1) * 256]
                bitvec_3 = a_3[i*256: (i + 1) * 256]

                if len(bitvec_1) > 0:
                    plaintext = (bitvec_1.int_val() * c1 + bitvec_2.int_val() * c2 + bitvec_3.int_val() * c3) % mod_N
                    cube_root = self.solve_pRoot(3, plaintext)
                    
                    plaintext_bv = BitVector(intVal = cube_root, size = 256)
                    rightmost_bits = plaintext_bv[128:]
                    
                    file.write(rightmost_bits.get_bitvector_in_ascii())
            
if __name__ == '__main__':
    cipher = RSA(e = 3)
    if sys.argv[1] == "-e":
        cipher.encrypt_3(plaintext = sys.argv[2], moduli = sys.argv[6])
    elif sys.argv[1] == "-c":    
         cipher.break_3(ciphertext_1 = sys.argv[2], ciphertext_2 = sys.argv[3], ciphertext_3 = sys.argv[4], recovered_plaintext = sys.argv[6])