/*
 * mario.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Simple program that forms a half-pyramid in which hashes represent blocks, similar to the half-pyramid found toward the end 
   of World 1-1 in Nintendo’s Super Mario Brothers 
 * The half-pyramid’s height which is entered by the user must be a non-negative integer no greater than 23.
 */


#include <cs50.h>
#include <stdio.h>

int main (void){


int n;
do{
    printf("Height: ");
    n=GetInt();
}
while (n<0||n>23);

int spaces = n - 1;
int temp = spaces;
    
for (int i=0; i<n; i++){
    
    for(; spaces!=0; spaces--){
        printf(" ");
    }

    for (int j=i+2;j>0;j--){
    printf("#");
    }
    
    printf("\n");
    
    spaces = temp;
    temp --;
    spaces--;
}

    
    
  return 0;  
}
