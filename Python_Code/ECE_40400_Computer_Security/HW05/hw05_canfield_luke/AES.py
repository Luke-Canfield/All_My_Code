import sys
from BitVector import *

#Functions: gen_tables, gen_subbytes_table, g_function, and gen_key_schedule_256 were all used from the Professor's lecture notes or downloadable code from that same lecture.
class AES():
    def __init__(self, keyfile:str) -> None:
        with open(keyfile, 'r') as file:
            self.key = BitVector(textstring=file.read())
        self.AES_mod = BitVector(bitstring='100011011')
        self.subBytesTable = []
        self.invSubBytesTable = []
    
    def gen_tables(self):
        c = BitVector(bitstring='01100011')
        d = BitVector(bitstring='00000101')
        for i in range(0, 256):
            a = BitVector(intVal=i, size=8).gf_MI(self.AES_mod, 8) if i != 0 else BitVector(intVal=0)
            a1, a2, a3, a4 = [a.deep_copy() for x in range(4)]
            a ^= (a1 >> 4) ^ (a2 >> 5) ^ (a3 >> 6) ^ (a4 >> 7) ^ c
            self.subBytesTable.append(int(a))
            b = BitVector(intVal=i, size=8)
            b1, b2, b3 = [b.deep_copy() for x in range(3)]
            b = (b1 >> 2) ^ (b2 >> 5) ^ (b3 >> 7) ^ d
            check = b.gf_MI(self.AES_mod, 8)
            b = check if isinstance(check, BitVector) else 0
            self.invSubBytesTable.append(int(b))
        return self.subBytesTable, self.invSubBytesTable
    
    def gen_subbytes_table(self):
        subBytesTable = []
        c = BitVector(bitstring='01100011')
        for i in range(0, 256):
            a = BitVector(intVal = i, size=8).gf_MI(self.AES_mod, 8) if i != 0 else BitVector(intVal=0)
            a1,a2,a3,a4 = [a.deep_copy() for x in range(4)]
            a ^= (a1 >> 4) ^ (a2 >> 5) ^ (a3 >> 6) ^ (a4 >> 7) ^ c
            subBytesTable.append(int(a))
        return subBytesTable
    
    def g_function(self, keyword, round_num_constant, byte_sub_table):
        rotated_word = keyword.deep_copy()
        rotated_word << 8
        newword = BitVector(size=0)
        for i in range(4):
            newword += BitVector(intVal=byte_sub_table[rotated_word[8 * i:8 * i + 8].intValue()], size=8)
        newword[:8] ^= round_num_constant
        round_num_constant = round_num_constant.gf_multiply_modular(BitVector(intVal=0x02), self.AES_mod, 8)
        return newword, round_num_constant
    
    def gen_key_schedule_256(self, key_bv):
        byte_sub_table = self.gen_subbytes_table()
        key_words = [None for i in range(60)]
        round_constant = BitVector(intVal = 0x01, size=8)
        for i in range(8):
            key_words[i] = key_bv[i*32 : i*32 + 32]
        for i in range(8,60):
            if i%8 == 0:
                kwd, round_constant = self.g_function(key_words[i-1], round_constant, byte_sub_table)
                key_words[i] = key_words[i-8] ^ kwd
            elif (i - (i//8)*8) < 4:
                key_words[i] = key_words[i-8] ^ key_words[i-1]
            elif (i - (i//8)*8) == 4:
                key_words[i] = BitVector(size = 0)
                for j in range(4):
                    key_words[i] += BitVector(intVal = 
                                    byte_sub_table[key_words[i-1][8*j:8*j+8].intValue()], size = 8)
                key_words[i] ^= key_words[i-8] 
            elif ((i - (i//8)*8) > 4) and ((i - (i//8)*8) < 8):
                key_words[i] = key_words[i-8] ^ key_words[i-1]
            else:
                sys.exit("error in key scheduling algo for i = %d" % i)
        return key_words
    
    def sub_bytes(self, subBytesTable, state_array):
        for i in range(4):
            for j in range(4):
                state_array[i][j] = BitVector(intVal=subBytesTable[int(state_array[i][j])])
                if len(state_array[i][j]) != 8:
                    state_array[i][j].pad_from_left(8 - len(state_array[i][j]))

    def shift_rows(self, temp_shift, state_array):
        for i in range(1,4):
            for j in range(0,4):
                temp_shift[(j-i)%4] = state_array[j][i]
            for j in range (0,4):
                state_array[j][i] = temp_shift[j]

    def mix_columns(self, round, state_array):
        if round != 13:
            mul_two = BitVector(bitstring='00000010')
            mul_three = BitVector(bitstring='00000011')
            for i in range(4):
                temp = (mul_two.gf_multiply_modular(state_array[i][0], self.AES_mod, 8)) ^ \
                                    (mul_three.gf_multiply_modular(state_array[i][1], self.AES_mod, 8)) ^ \
                                    state_array[i][2] ^ \
                                    state_array[i][3]

                temp1 = (mul_two.gf_multiply_modular(state_array[i][1], self.AES_mod, 8)) ^ \
                                    (mul_three.gf_multiply_modular(state_array[i][2], self.AES_mod, 8)) ^ \
                                    state_array[i][3] ^ \
                                    state_array[i][0]

                temp2 = (mul_two.gf_multiply_modular(state_array[i][2], self.AES_mod, 8)) ^ \
                                    (mul_three.gf_multiply_modular(state_array[i][3], self.AES_mod, 8)) ^ \
                                    state_array[i][0] ^ \
                                    state_array[i][1]

                temp3 = (mul_two.gf_multiply_modular(state_array[i][3], self.AES_mod, 8)) ^ \
                                    (mul_three.gf_multiply_modular(state_array[i][0], self.AES_mod, 8)) ^ \
                                    state_array[i][1] ^ \
                                    state_array[i][2]

                state_array[i][0] = temp
                state_array[i][1] = temp1
                state_array[i][2] = temp2
                state_array[i][3] = temp3

    def add_r_key(self, key_words, round, state_array, ctrl):
        for i in range(4):
            for j in range(4):
                if ctrl == 1:
                    state_array[i][j] ^= key_words[(4 * (round + 1)) + i][8 * j:8 + (8 * j)]
                if ctrl == 0:
                    state_array[i][j] ^= key_words[(4* (round - 1)) + i][8 * j:8 + (8 * j)]

    def encrypt(self, iv, key_words, subBytesTable):
        state_array = [[0 for x in range(4)] for x in range(4)]
        temp_shift = [0] * 4
        ctrl = 1
   
        for i in range(4):
            for j in range(4):
                state_array[i][j] = iv[32 * i + 8 * j:32 * i + 8 * (j + 1)]
                state_array[i][j] ^= key_words[i][8 * j:8 + (8 * j)]

        for round_num in range(14):
            self.sub_bytes(subBytesTable, state_array)
            self.shift_rows(temp_shift, state_array)
            self.mix_columns(round_num, state_array)        
            self.add_r_key(key_words, round_num, state_array, ctrl)        
        return state_array
        
    def ctr_aes_image(self, iv, image_file, enc_image):
        key_words = self.gen_key_schedule_256(self.key)
        subBytesTable, _ = self.gen_tables()
        bv = BitVector(filename=image_file)

        with open(image_file, 'rb') as file:
            header_lines = [file.readline().strip() for _ in range(3)]
        header = b'\n'.join(header_lines) + b'\n'

        bv.read_bits_from_file(112)    

        with open(enc_image, 'wb') as file:
            file.write(header)
        
            while bv.more_to_read:
                bitvec = bv.read_bits_from_file(128)
                if len(bitvec) > 0:
                    if len(bitvec) != 128:
                        bitvec.pad_from_right(128 - len(bitvec))
                    if len(iv) != 128:
                        iv.pad_from_right(128 - len(iv))
                    state_array = self.encrypt(iv, key_words, subBytesTable)
                    encrypted_block = BitVector(size=128)
                    for i in range(4):
                        for j in range(4):
                            encrypted_block[32 * i + 8 * j:32 * i + 8 * (j + 1)] = state_array[i][j]
                    
                    cipher_block = encrypted_block ^ bitvec
                    iv = BitVector(intVal=iv.intValue() + 1,size=128)
                    cipher_block.write_to_file(file)
        
    def x931(self, v0, dt, totalNum, outfile):
        key_words = self.gen_key_schedule_256(self.key)
        subBytesTable, _ = self.gen_tables()
        x = 0

        AES_dt = self.encrypt(dt, key_words, subBytesTable)
        bitvec_AES_dt = BitVector(size=128)
        for i in range(4):
            for j in range(4):
                bitvec_AES_dt[32 * i + 8 * j:32 * i + 8 * (j + 1)] = AES_dt[i][j]

        while x < totalNum:
            file = open(outfile, 'a')
            new_vec = bitvec_AES_dt ^ v0
            random_num = self.encrypt(new_vec, key_words, subBytesTable)
            bitvec_rand_num = BitVector(size=128)
            for i in range(4):
                for j in range(4):
                    bitvec_rand_num[32 * i + 8 * j:32 * i + 8 * (j + 1)] = random_num[i][j]

            output = bitvec_rand_num.intValue()

            next_v = bitvec_AES_dt ^ bitvec_rand_num
            v_j = self.encrypt(next_v, key_words, subBytesTable)
            for i in range(4):
                for j in range(4):
                    v0[32 * i + 8 * j:32 * i + 8 * (j + 1)] = v_j[i][j]
            file.write(str(output) + '\n')
            file.close
            x += 1 

if __name__ == '__main__':
    cipher = AES(keyfile = sys.argv[3])
    if sys.argv[1] == "-e":
        cipher.encrypt(plaintext=sys.argv[2], ciphertext=sys.argv[4])
    elif sys.argv[1] == "-i":
        cipher.ctr_aes_image(iv = BitVector(textstring="counter-mode-ctr"), image_file=sys.argv[2], enc_image=sys.argv[4])
    else:
        cipher.x931(v0=BitVector(textstring="counter-mode-ctr"), dt=BitVector(intVal=501,size=128), totalNum=int(sys.argv[2]), outfile=sys.argv[4])
