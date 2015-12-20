#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>      

int main(int argc, string argv[])
{
    // check for argument availability
    if (argc != 2)
    {
        printf("I need one non-negative number as an argument, silly!!\n");     
        return 1;
    }
    
    // check for valid argument
    int key = atoi(argv[1]) % 26;
    if (key < 0)
    {
        printf("I need one non-negative number as an argument, silly!!\n");     
        return 1;
    }

    // printf("Put in a text here, pleeease:\n");
    string text = GetString();
    for (int i = 0; i < strlen(text); i++)
    { 
        if (isupper(text[i]))
        {
            printf("%c", 'A' + (text[i] - 'A' + key) % 26);
        }
        else if (islower(text[i]))
        {
            printf("%c", 'a' + (text[i] - 'a' + key) % 26);
        }
        else 
        {
            printf("%c", text[i]);
        }
        
    }
    printf("\n");
    return 0;
}
