/*
 * initials.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Basic program that takes in the name of a person and prints out their initials. 
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void){

string input = GetString();

printf("%c",toupper(input[0]));

for (int i=0, n=strlen(input); i<n-1; i++){
if(input[i]==' ') printf("%c",toupper(input[i+1]));
}

printf("\n");  

}
