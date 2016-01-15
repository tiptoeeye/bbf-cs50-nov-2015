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
#include <string.h>


int main(int argc, char* argv[])
{
    int CHUNK = 512;
    FILE* fp = fopen("card.raw", "r");
    int checkBytes[4] = {0xff, 0xd8, 0xff, 0xe0};
    int buffer[CHUNK];
    
    int jgpcount = 1;
    
    FILE* fpJpg;
    
    int open = 0;
    char newJpg[8];
    //printf("%#08x\n", checkBytes[0]);
    //printf("%#08x\n", checkBytes[3]);
    while(fread(buffer, CHUNK, 1, fp)>0)
    {
        int flag = 0;
        int i = 0;
        while(i<CHUNK)
        {
            int check[4];
            for(int j=0; j<4; j++)
            {
                check[j] = buffer[i];
                i++;
            }
            if(memcmp(checkBytes, check, 4) == 0)
            {
                flag = 1;
                break;
            }
        }
        //printf("AAA\n");
        //char str2[30];
        //scanf("%s", str2);
        if(flag == 1) 
        {
            //printf("%#08x\n", buffer[i]);
            if(open == 0)
            {
                open = 1;
            }
            else
            {
                printf("File %s closed\n", newJpg);
                char str2[30];
                scanf("%s", str2);
                fclose(fpJpg);
                jgpcount++;
            }
            sprintf(newJpg, "%i.jpg", jgpcount);
            fpJpg = fopen(newJpg, "w");
            fwrite(buffer, sizeof(buffer), 1, fpJpg);
        }
        else
        {
            if(open==1)
            {
                fwrite(buffer, sizeof(buffer), 1, fpJpg);
            }
        }
    }
    if(open==1)
        fclose(fpJpg);
    fclose(fp);
}
