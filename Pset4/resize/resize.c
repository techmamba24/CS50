/*
 * resize.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Basic program that enlarges an inputted BMP image to desired size, and outputs it as a new BMP file.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);
    
    if (n>100||n<1){
        fprintf(stderr, "Cannot scale to this value\n");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    int oldbiWidth =  bi.biWidth;
    
    int oldbiHeight = bi.biHeight;
    
    bi.biWidth*=n;
    
    bi.biHeight*=n;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // determine padding for scanlines
    int oldpadding = (4 - (oldbiWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biSizeImage = ((sizeof(RGBTRIPLE)*bi.biWidth)+padding)*abs(bi.biHeight);
    
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    for (int i = 0, biHeight = abs(oldbiHeight); i < biHeight; i++) {
        
        RGBTRIPLE triples [bi.biWidth];
        
        int counter=0;
        
        for (int j = 0; j < oldbiWidth; j++){
            
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int k=0; k<n; k++){
                triples[counter]= triple;
                counter++;
            }
            
        }
        
        fseek(inptr, oldpadding, SEEK_CUR);

        for (int z=0; z<n; z++){
            
        fwrite(&triples, sizeof(RGBTRIPLE), bi.biWidth, outptr);

        for (int k = 0; k < padding; k++) fputc(0x00, outptr);
                
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
