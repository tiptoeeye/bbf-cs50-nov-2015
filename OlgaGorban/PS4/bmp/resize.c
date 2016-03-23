/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    //remember scale factor
    int n = atoi(argv[1]);
    
    //check the scale factor
    if((n<1) || (n>100))
    {
        printf("The scale factor must be larger than 0 and smaller than 100\n");
        return 5;
    }
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
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

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
 
    //TODO
    //outfile`s header`s
    BITMAPFILEHEADER bf_r = bf;
    BITMAPINFOHEADER bi_r = bi;
    
    //determine new heder`s
    bi_r.biWidth = bi.biWidth*n;
    bi_r.biHeight = bi.biHeight*n;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //calculate the padding
    int padding_r = (4-(bi_r.biWidth * sizeof(RGBTRIPLE))%4)%4;
    
    bi_r.biSizeImage = (sizeof(RGBTRIPLE)*abs(bi_r.biHeight)*bi_r.biWidth) + (bi_r.biWidth*padding_r);
    bf_r.bfSize = bi_r.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_r, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_r, sizeof(BITMAPINFOHEADER), 1, outptr);

    // length of line
    int offset = bi.biWidth*sizeof(RGBTRIPLE) + padding;
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int vertical_copy = 0; vertical_copy < n; vertical_copy++)
        {
        
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int horizontal_copy = 0; horizontal_copy < n; horizontal_copy++)
                {    
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back
        for (int k = 0; k < padding_r; k++)
        {
            fputc(0x00, outptr);
        }
        
        //return the pointer
        fseek(inptr, -offset, SEEK_CUR);
        }
        
    //move the pointer to next line
    fseek(inptr, offset, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
