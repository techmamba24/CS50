/*
 * water.c
 * Aamel Unia
 * aameluni@buffalo.edu
 */
#include <cs50.h>
#include <stdio.h>

int main (void){
    
    //Get user input
    printf("minutes: ");
    int showerlength = GetInt();
    //Calculate number of bottles of water used during shower based on inputted time.
    int bottles = ((showerlength*1.5)*128)/16;
    //print out result
    printf("bottles: %i \n",bottles);
    return 0;
}
