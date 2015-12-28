#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 8


static const char alphabet[] =
"!\"#$%&'()+,-./:;<=>?@[\\]^_`{|}~"
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789";

static const int alphabetSize = sizeof(alphabet) - 1;

void bruteImpl(char* str, int index, int maxDepth, char* word, char* salt);
void bruteSequential(char* word, char* salt);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("You should have inserted only one argument, fool!\n");
        return 1;
    }
    
    char* word = argv[1];
    char* salt = (char*) malloc(2);   
    strncpy(salt, argv[1], 2);
 
    bruteSequential(word, salt);
    
    return 0;
}

void bruteImpl(char* str, int index, int maxDepth, char* word, char* salt)
{
    for (int i = 0; i < alphabetSize; ++i)
    {
        str[index] = alphabet[i];

        if (index == maxDepth - 1)
        {
            if (strcmp(crypt(str, salt), word) == 0)
            {
                printf("Password: %s\n", str);
                exit(0);
            }
            else
            {
                //printf("%s - %s\n", str, crypt(str,"50"));
            }  
        }
        else 
        {
            //printf("%s\n", str);
            bruteImpl(str, index + 1, maxDepth, word, salt);
        }
    }
}

void bruteSequential(char* word, char* salt)
{
    char* buf = malloc(MAX_LENGTH + 1);

    for (int i = 1; i <= MAX_LENGTH; ++i)
    {
        memset(buf, 0, MAX_LENGTH + 1);
        bruteImpl(buf, 0, i, word, salt);
    }

    free(buf);
}
