/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int buffer[128];

    char name[8];
    
    int num = 0;
    
    sprintf (name, "00%i.jpg", num);

    FILE* copy = fopen(name, "w");
    FILE* raw = fopen("card.raw", "r");
    
    while(fread(buffer, 512, 1, raw)) {
        if (buffer[0] == 0xe0ffd8ff ||
           buffer[0] == 0xe1ffd8ff ||
           buffer[0] == 0xe2ffd8ff ||
           buffer[0] == 0xe3ffd8ff ||
           buffer[0] == 0xe4ffd8ff ||
           buffer[0] == 0xe5ffd8ff ||
           buffer[0] == 0xe6ffd8ff ||
           buffer[0] == 0xe7ffd8ff ||
           buffer[0] == 0xe8ffd8ff ||
           buffer[0] == 0xe9ffd8ff ||
           buffer[0] == 0xeaffd8ff ||
           buffer[0] == 0xebffd8ff ||
           buffer[0] == 0xecffd8ff ||
           buffer[0] == 0xedffd8ff ||
           buffer[0] == 0xeeffd8ff ||
           buffer[0] == 0xefffd8ff) 
        {
            fwrite(buffer, 512, 1, copy);
            while(fread(buffer, 512, 1, raw)) {
                if (buffer[0] != 0xe0ffd8ff &&
                buffer[0] != 0xe1ffd8ff &&
                buffer[0] != 0xe2ffd8ff &&
                buffer[0] != 0xe3ffd8ff &&
                buffer[0] != 0xe4ffd8ff &&
                buffer[0] != 0xe5ffd8ff &&
                buffer[0] != 0xe6ffd8ff &&
                buffer[0] != 0xe7ffd8ff &&
                buffer[0] != 0xe8ffd8ff &&
                buffer[0] != 0xe9ffd8ff &&
                buffer[0] != 0xeaffd8ff &&
                buffer[0] != 0xebffd8ff &&
                buffer[0] != 0xecffd8ff &&
                buffer[0] != 0xedffd8ff &&
                buffer[0] != 0xeeffd8ff &&
                buffer[0] != 0xefffd8ff) 
                {
                    fwrite(buffer, 512, 1, copy);
                }
                else 
                {
                    fseek(raw, -512, SEEK_CUR);
                    
                    // close outfile
                    fclose(copy);
                    num++;
                    if (num < 10) {
                        sprintf (name, "00%i.jpg", num); 
                    } else {
                        sprintf (name, "0%i.jpg", num);
                    }
                    copy = fopen(name, "w");
                    break; 
                }
                
            }
            
            
        }


    }
    
    fclose(copy);
    
    // close infile
    fclose(raw);

    // that's all folks
    return 0;
}

