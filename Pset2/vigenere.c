/*
 * vigenere.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Basic implementation of the Vigenere Cipher.
 */


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[]){
    
if (argc!=2) {
    printf("Incorrect number of arguments!\n"); 
    return 1;
}

string key = argv[1];
int keylen = strlen(key);

for (int i=0; i<keylen; i++){
    if(!isalpha(key[i])) {
        printf("Incorrect argument!\n");
        return 1;
    }
}

string text = GetString();


for (int i=0, counter=0, n=strlen(text); i<n; i++){
    
    if(isalpha(text[i])){
        
        if(islower(text[i])){
            
             if(islower(key[counter%keylen])){
                char temp = (key[counter%keylen]-'a' + text[i]-'a')%26 + 97; 
                text[i]=temp;
             }
             if(isupper(key[counter%keylen])){
                char temp = (key[counter%keylen]-'A' + text[i]-'a')%26 + 97; 
                text[i]=temp;
             }
             
         }
    
        else if(isupper(text[i])){
            
            if(islower(key[counter%keylen])){
                char temp = (key[counter%keylen]-'a' + text[i]-'A')%26 + 65; 
                text[i]=temp;
             }
            if(isupper(key[counter%keylen])){
                char temp = (key[counter%keylen]-'A' + text[i]-'A')%26 + 65; 
                text[i]=temp;
             }
        }
        
        counter++;
    }
}

printf("%s\n", text);

return 0;
}
