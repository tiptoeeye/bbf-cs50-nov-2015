#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void) { //(int argc, string argv[])
    
    int k;
    string s;
    
    // check if k is positive int
    do {
        printf("Please, give me a non-negative key:\n");
    k = GetInt(); }
    while (k<0);
    
    // check if argc = 2
//    if (argc >2 || argc < 2) {
//        printf("The unappropriate key! Please, give me only the key!/n");
//        return 1;
//    }
    
    
    printf("Please, give me a string:\n");
    s = GetString();
    for (int i = 0; i < strlen(s); i++)
    { 
        if (isupper(s[i]) && isalpha(s[i]))
        {
            printf("%c", 'A' + (s[i] - 'A' + k) % 26);
        }
        else if (islower(s[i]) && isalpha(s[i]))
        {
            printf("%c", 'a' + (s[i] - 'a' + k) % 26);
        }
        else 
        {
            printf("%c", s[i]);
        }
        
    }
    printf("\n");

   return 0; 
}