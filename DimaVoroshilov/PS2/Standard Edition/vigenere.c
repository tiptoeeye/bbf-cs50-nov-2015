#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>      

int main(int argc, string argv[])
{
    // check for argument availability
    if (argc != 2)
    {
        printf("I need one word as an argument, silly!!\n");  
        return 1;
    }
    
    // check for valid argument
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("I need a word of letters only, silly!!\n");
            return 1;
        }
    }
    
    string text = GetString();
    
    int j = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        // key assignment
        int key_pos = j % strlen(argv[1]);
        
        char key = argv[1][key_pos];
        
        if (isupper(key))
        {
            key -= 'A';
        }
        else
        {
            key -= 'a';
        }
        
        // decoding
        if (isupper(text[i]))
        {
            printf("%c", 'A' + (text[i] - 'A' + key) % 26);
            j++;
        }
        else if (islower(text[i]))
        {
            printf("%c", 'a' + (text[i] - 'a' + key) % 26);
            j++;
        }
        else 
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    
    return 0;
}

/*
printf("%i\n", key_pos);

*/
