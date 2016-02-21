/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define CHUNK 512

int main(int argc, char* argv[])
{
    FILE* fp = fopen ("card.raw", "r");
    
    if(fp == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    uint8_t checkBytes[4] = {0xff, 0xd8, 0xff, 0xe0};
    
    int jpgcount = 0;
    int open = 0;
    
    FILE* fpJpg;
    
    uint8_t buffer [CHUNK];
    uint8_t check[4];
    
    fread (buffer, CHUNK, 1, fp);
    
    while (fread (buffer, CHUNK, 1, fp)>0)
    {
        //first 4 bytes
        for(int i=0; i<4; i++)
        {
            check[i] = buffer[i];
        }
        
        if(memcmp(checkBytes, check, 4)==0)
        {
            char filename[8];
            sprintf(filename, "%03d.jpg", jpgcount);
        
            if(open == 0)
            {
                fpJpg = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, fpJpg);
                open = 1;
            }
            
            else
            {
                fclose(fpJpg);
                fpJpg = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, fpJpg);
                jpgcount++;
            }
        }
        else
        {
            if (open == 1)
            {
                fwrite(buffer, sizeof(buffer), 1, fpJpg);  
            }
        }
    }
    
    if(fpJpg)
    {
        fclose(fpJpg);
    }
    
    fclose(fp);
    return 0;
    
    
}
