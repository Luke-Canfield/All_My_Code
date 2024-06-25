from cryptBreak import cryptBreak
from BitVector import *                                                     

randInt = 9999
key_bv = BitVector(intVal=randInt, size=16)
decryptMessage = cryptBreak('cipherText.txt', key_bv)
if 'Ferrari' in decryptMessage:
    print('Encryption Broken')
else:
    print('Not decrypted yet')
