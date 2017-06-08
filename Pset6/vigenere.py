#   vigenere.py
#   Aamel Unia
#   aameluni@buffalo.edu
#   Basic implementation of the Vigenere Cipher.

import sys

def main():
    if len(sys.argv)!=2:
        print("Usage: python vigenere.py k")
        exit(1)
        
    key = sys.argv[1]
    
    for i in range(len(key)):
        if not key[i].isalpha():
            print("Usage: python vigenere.py k")
            exit(1)
            
    print("plaintext: ",end="")
    plaintext = input()
    
    ciphertext=""
    counter=0
    
    for c in plaintext:
        if c.isalpha():
            index = counter%len(key)
            if c.islower():
                temp = ( (ord(key[index]) - ord('a')) + (ord(c) - ord('a')) )%26+97 if key[index].islower() else ( (ord(key[index])-ord('A')) + (ord(c)-ord('a')) )%26+97
                ciphertext+=chr(temp)
            elif c.isupper():
                temp = ( (ord(key[index]) - ord('a')) + (ord(c) - ord('A')) )%26+65 if key[index].islower() else ( (ord(key[index])-ord('A')) + (ord(c)-ord('A')) )%26+65
                ciphertext+=chr(temp)
            counter+=1
        else:
            ciphertext+=c
            
    print(ciphertext)
    
    
if __name__ == "__main__":
    main()
    exit(0)