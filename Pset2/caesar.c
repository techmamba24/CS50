/*
 * caesar.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Basic implementation of the Caesar Cipher.
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

int key = atoi(argv[1]);
string text= GetString();

for (int i=0, n=strlen(text); i<n; i++){
    
    if(isalpha(text[i])){
        
        if(islower(text[i])){
           char temp = (key + text[i]-'a')%26 + 97; 
           text[i]=temp;
        }
        else{
            char temp = (key + text[i]-'A')%26 + 65; 
            text[i]=temp;
        }
        
    }
    
}

printf("%s\n", text);

return 0;    
}
