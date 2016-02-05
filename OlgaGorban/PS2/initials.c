#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    
    printf("Please, type your name:\n");
    string s = GetString();
    
    for ( int n = 0; n < strlen(s); n++) {
        if (!isalpha(s[n]) && s[n]!=' ') {
            printf("You've entered non-alphabetical chars!\n"); 
            return 1;  
        }
    }
    
    printf("Your initials are: %c", toupper(s[0]));
   
    for ( int i = 0, n = strlen(s); i <= n; i++) {
        if ( s[i] == ' ')
        {
            printf("%c",toupper(s[i + 1])); 
            i++;
        }
    }
    printf("\n"); 
}