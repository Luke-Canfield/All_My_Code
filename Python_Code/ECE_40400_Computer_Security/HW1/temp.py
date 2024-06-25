import sys
from BitVector import *                                                     

if len(sys.argv) is not 3:                                                  
    sys.exit('''Needs two command-line arguments, one for '''
             '''the encrypted file and the other for the '''
             '''decrypted output file''')
                      
def cryptBreak(cipherFile, key_val):
    PassPhrase = "Hopes and dreams of a million years"                          

    BLOCKSIZE = 16                                                                  
    numbytes = BLOCKSIZE // 8                                                   

# Reduce the passphrase to a bit array of size BLOCKSIZE:
    bv_iv = BitVector(bitlist = [0]*BLOCKSIZE)                                  
    for i in range(0,len(PassPhrase) // numbytes):                              
        textstr = PassPhrase[i*numbytes:(i+1)*numbytes]                         
        bv_iv ^= BitVector( textstring = textstr )                              

# Create a bitvector from the ciphertext hex string:
    FILEIN = open(cipherFile)                                                  
    encrypted_bv = BitVector( hexstring = FILEIN.read() )
# Reduce the key to a bit array of size BLOCKSIZE:
    key_bv = BitVector(bitlist = [0]*BLOCKSIZE)                                 
    key_bv ^= key_val                           

# Create a bitvector for storing the decrypted plaintext bit array:
    msg_decrypted_bv = BitVector( size = 0 )                                    

# Carry out differential XORing of bit blocks and decryption:
    previous_decrypted_block = bv_iv                                            
    for i in range(0, len(encrypted_bv) // BLOCKSIZE):                          
        bv = encrypted_bv[i*BLOCKSIZE:(i+1)*BLOCKSIZE]                          
        temp = bv.deep_copy()                                                   
        bv ^=  previous_decrypted_block                                         
        previous_decrypted_block = temp                                         
        bv ^=  key_bv                                                           
        msg_decrypted_bv += bv                                                  

# Extract plaintext from the decrypted bitvector:    
    outputtext = msg_decrypted_bv.get_text_from_bitvector()
    return outputtext                                                     

for key_val in range (2**16):
    key_bv = BitVector(intVal=key_val, size=16)
    outputtext = cryptBreak("cipherText.txt",key_bv)
    if "Ferrari" in outputtext:
        print(key_val)
        print(outputtext)
# Write plaintext to the output file:
        FILEOUT = open(sys.argv[2], 'w')                                            
        FILEOUT.write(outputtext)                                                   
        FILEOUT.close()
        sys.exit()
                                                  