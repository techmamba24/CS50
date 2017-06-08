/*
 * recover.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Basic program that recovers JPEGs from a forensic image as per specifications provided in problem set.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef uint8_t byte;

int main(int argc, char *argv[]){

if (argc!=2){
    
     fprintf(stderr, "Usage: ./recover jpegfile\n");
     return 1;
} 

char *input = argv[1];

FILE *file = fopen(argv[1], "r");
if (file == NULL){
    
    fprintf(stderr, "Could not open %s.\n", input);
    return 2;
}    

int filecounter=0;

char output[10];

FILE *img;

while (!feof(file)){

byte buffer[512];

int itemsread = fread (buffer, 1, 512, file);
if (itemsread!=512) break;

if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0){
    
    if (filecounter==0){
    sprintf(output, "%03i.jpg", filecounter);
    img = fopen(output, "w");
    filecounter++;
    }
    
    else if (filecounter>0) {
    fclose(img);
    sprintf(output, "%03i.jpg", filecounter);
    img = fopen(output, "w");
    filecounter++;
    }

}
 
 if (filecounter!=0) fwrite (buffer, 1, 512, img); 

}
    
return 0;    

}