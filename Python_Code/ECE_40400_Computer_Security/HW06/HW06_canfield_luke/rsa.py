import sys
from BitVector import *
     
class RSA():
    def __init__ (self, e) -> None :
        self.e = e
        self.n = None
        self.d = None
        self.p = None
        self.q = None

    def encrypt(self, plaintext:str, ciphertext :str) -> None :
        with open(sys.argv[3], 'r') as file:
            self.p = int(file.read())
        with open(sys.argv[4], 'r') as file:
            self.q = int(file.read())
        bv = BitVector(filename = plaintext)
        self.n = self.p * self.q

        with open(ciphertext, 'w') as file:
            while bv.more_to_read:
                bitvec = bv.read_bits_from_file(128)
                if len(bitvec) > 0:
                    if len(bitvec) != 128:
                        bitvec.pad_from_right(128 - len(bitvec))
                    bitvec.pad_from_left(128)
                    cipher_int = pow(bitvec.int_val(), self.e, self.n)
                    cipher = BitVector(intVal=cipher_int, size=256)

                    file.write(cipher.get_bitvector_in_hex())
                    
        
    def decrypt(self, ciphertext :str, recovered_plaintext:str) -> None :
        FILE = open(ciphertext, 'r') 
        bv = BitVector(hexstring = FILE.read())
        
        with open(sys.argv[3], 'r') as file:
            self.p = int(file.read())
        with open(sys.argv[4], 'r') as file:
            self.q = int(file.read())

        self.n = self.p * self.q
        totient_n = (self.p - 1) * (self.q - 1)

        bv_e = BitVector(intVal = self.e)
        bv_totient = BitVector(intVal = totient_n)
        self.d = bv_e.multiplicative_inverse(bv_totient)

        bv_q = BitVector(intVal = self.q)
        bv_p = BitVector(intVal = self.p)
        Xp = bv_q.int_val() * bv_q.multiplicative_inverse(bv_p).int_val()
        Xq = bv_p.int_val() * bv_p.multiplicative_inverse(bv_q).int_val()
        
        with open(recovered_plaintext, 'w') as file:
            for i in range(len(bv) // 256):
                bitvec = bv[i*256: (i + 1) * 256]
                if len(bitvec) > 0:
                    Vp = pow(bitvec.int_val(), self.d.int_val(), self.p)
                    Vq = pow(bitvec.int_val(), self.d.int_val(), self.q)
                    plaintext = ((Vp * Xp) + (Vq * Xq)) % self.n
                    plaintext_bv = BitVector(intVal = plaintext, size=256)
                    rightmost_bits = plaintext_bv[128:]
                    file.write(rightmost_bits.get_bitvector_in_ascii())

if __name__ == '__main__':
    cipher = RSA(e = 65537)
    if sys.argv[1] == "-e":
        cipher.encrypt(plaintext = sys.argv[2], ciphertext = sys.argv[5])
    elif sys.argv[1] == "-d":    
         cipher.decrypt(ciphertext = sys.argv[2],recovered_plaintext = sys.argv[5])