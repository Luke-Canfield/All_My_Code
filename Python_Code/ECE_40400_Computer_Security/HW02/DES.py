#All of this code besides the encrypt/decrypt functions (which we were given starter code for encrpt) was adapted or used from the Professor's Lecture 3 code
import sys
from BitVector import *
import binascii

class DES:
    def __init__(self):
        self.expansion_permutation = [31, 0, 1, 2, 3, 4, 3, 4, 5, 6, 7, 8, 7, 8, 9,
                         10, 11, 12, 11, 12, 13, 14, 15, 16, 15, 16,
                         17, 18, 19, 20, 19, 20, 21, 22, 23, 24, 23,
                         24, 25, 26, 27, 28, 27, 28, 29, 30, 31, 0]
        self.p_box_permutation = [ 15,  6, 19, 20, 28, 11, 27, 16,
                      0, 14, 22, 25,  4, 17, 30,  9,
                      1,  7, 23, 13, 31, 26,  2,  8,
                     18, 12, 29,  5, 21, 10,  3, 24 ]
        self.key_permutation_1 = [56,48,40,32,24,16,8,0,57,49,41,33,25,17,
                      9,1,58,50,42,34,26,18,10,2,59,51,43,35,
                     62,54,46,38,30,22,14,6,61,53,45,37,29,21,
                     13,5,60,52,44,36,28,20,12,4,27,19,11,3]
        self.key_permutation_2 = [13,16,10,23,0,4,2,27,14,5,20,9,22,18,11,
                      3,25,7,15,6,26,19,12,1,40,51,30,36,46,
                     54,29,39,50,44,32,47,43,48,38,55,33,52,
                     45,41,49,35,28,31]
        self.shifts_for_round_key_gen = [1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1]
        self.s_boxes = {i: None for i in range(8)}
        self.s_boxes[0] = [ [14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],
               [0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],
               [4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0],
               [15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13] ]

        self.s_boxes[1] = [ [15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10],
               [3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5],
               [0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15],
               [13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9] ]

        self.s_boxes[2] = [ [10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8],
                    [13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1],
                    [13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7],
                    [1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12] ]

        self.s_boxes[3] = [ [7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15],
                    [13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9],
                    [10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4],
                    [3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14] ]

        self.s_boxes[4] = [ [2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9],
                    [14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6],
                    [4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14],
                    [11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3] ]  

        self.s_boxes[5] = [ [12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11],
                    [10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8],
                    [9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6],
                    [4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13] ]

        self.s_boxes[6] = [ [4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1],
                    [13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6],
                    [1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2],
                    [6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12] ]

        self.s_boxes[7] = [ [13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7],
                    [1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2],
                    [7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8],
                    [2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11] ]
        
    def substitute(self, expanded_half_block):  
        s_boxes_output = BitVector(size=32)
        blocks = [expanded_half_block[i*6:i*6+6] for i in range(8)]
        for i in range(len(blocks)):
            row_index = int(2*blocks[i][0] + blocks[i][-1])
            col_index = int(blocks[i][1:-1])
            s_boxes_output[i*4:i*4+4] = BitVector(intVal=self.s_boxes[i][row_index][col_index], size=4)
        return s_boxes_output
        
    def get_encryption_key(self, key_file):
        while True:
            with open(key_file, 'r') as f:
                string_key = f.readlines()[0]
            if len(string_key) != 8:
                print("\nNeed 8 characters exactly for key.\n")
                continue
            else:
                break
        key = BitVector(textstring=string_key)
        key = key.permute(self.key_permutation_1)
        return key
        
    def generate_round_keys(self, encryption_key):
        round_keys = []
        for round_count in range(16):
            [LKey, RKey] = encryption_key.divide_into_two()
            shift = self.shifts_for_round_key_gen[round_count]
            LKey << shift
            RKey << shift
            key = LKey + RKey
            round_key = key.permute(self.key_permutation_2)
            round_keys.append(round_key)
        return round_keys
        
    def encrypt(self, inputfile, outputfile):
        key = self.get_encryption_key(sys.argv[3])
        round_keys = self.generate_round_keys(key)
        bv = BitVector(filename=inputfile)
        FILEOUT = open(outputfile, 'w')
        while bv.more_to_read:
            bitvec = bv.read_bits_from_file(64)
            if len(bitvec) > 0:
                if len(bitvec) != 64:
                    bitvec.pad_from_right(64-len(bitvec))
                [LE, RE] = bitvec.divide_into_two()
                for round_key in round_keys:
                    newRE = RE.permute(self.expansion_permutation)
                    out_xor = newRE ^ round_key
                    s_box_output = self.substitute(out_xor)
                    p_box_output = s_box_output.permute(self.p_box_permutation)
                    RE_modified = p_box_output ^ LE
                    LE = RE
                    RE = RE_modified
                final_bitvec = RE + LE                
                hex_string = final_bitvec.get_hex_string_from_bitvector()
                FILEOUT.write(hex_string)
        FILEOUT.close()
        return
        
    def decrypt(self, inputfile, outputfile):
        key = self.get_encryption_key(sys.argv[3])
        round_keys = self.generate_round_keys(key)
        round_keys.reverse()

        with open(inputfile, 'r') as FILEIN:
            hex_string = FILEIN.read().strip()
            
        binary_data = bytes.fromhex(hex_string)
        with open(inputfile, 'wb') as file:
            file.write(binary_data)
        
        bv = BitVector(filename=inputfile)
        FILEOUT = open(outputfile, 'ab')
        while bv.more_to_read:
            bitvec = bv.read_bits_from_file(64)
            if len(bitvec) > 0:
                if len(bitvec) != 64:
                    bitvec.pad_from_right(64-len(bitvec))
                [LE, RE] = bitvec.divide_into_two()
                for round_key in round_keys:
                    newRE = RE.permute(self.expansion_permutation)
                    out_xor = newRE ^ round_key
                    s_box_output = self.substitute(out_xor)
                    p_box_output = s_box_output.permute(self.p_box_permutation)
                    RE_modified = p_box_output ^ LE
                    LE = RE
                    RE = RE_modified
                final_bitvec = RE + LE
                final_bitvec.write_to_file(FILEOUT)
        FILEOUT.close()
        with open(inputfile, 'w') as file:
            file.write(hex_string)
        return
    
    def encrypt_image(self, inputfile, outputfile):
        key = self.get_encryption_key(sys.argv[3])
        round_keys = self.generate_round_keys(key)

        with open(inputfile, 'rb') as file:
            for _ in range(3):
                header = b""
                header += file.readline()   

        bv = BitVector(filename=inputfile)
        FILEOUT = open(outputfile, 'wb')
        FILEOUT.write(header)

        while bv.more_to_read:
            bitvec = bv.read_bits_from_file(64)
            if len(bitvec) > 0:
                if len(bitvec) != 64:
                    bitvec.pad_from_right(64-len(bitvec))
                [LE, RE] = bitvec.divide_into_two()
                for round_key in round_keys:
                    newRE = RE.permute(self.expansion_permutation)
                    out_xor = newRE ^ round_key
                    s_box_output = self.substitute(out_xor)
                    p_box_output = s_box_output.permute(self.p_box_permutation)
                    RE_modified = p_box_output ^ LE
                    LE = RE
                    RE = RE_modified
                final_bitvec = RE + LE   

                final_bitvec.write_to_file(FILEOUT)

        FILEOUT.close()
        return

if __name__ == '__main__':
    instance = DES()

    if sys.argv[1] == "-e":
        instance.encrypt(sys.argv[2], sys.argv[4])
    if sys.argv[1] == "-d":
        instance.decrypt(sys.argv[2], sys.argv[4])
    if sys.argv[1] == "-i":
        instance.encrypt_image(sys.argv[2], sys.argv[4])

