#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // getting string from the user
    string n = GetString();
    
    // assigning var initial to the first letter of the string 
    char initial = n[0]; 
    
    for (int i = 1; i < strlen(n); i++)
    {
        // detecting the end of the word
        if (isalpha(n[i]) && !isalpha(n[i - 1]))
        {
            initial = n[i];
        }
        
        // detecting the beginning of the new word and printing an initial
        else if (!isalpha(n[i]) && isalpha(n[i - 1]) && isalpha(initial))
        {
            printf("%c", toupper(initial));
            initial = ' ';
        }
    }
    
    // printing out the last initial if necessary
    if (isalpha(initial) && n[strlen(n) - 1] != ' ')
    {
        printf("%c", toupper(initial));
    }
    
    printf("\n");
}


