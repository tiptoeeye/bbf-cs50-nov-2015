#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void) {
    
    string k;
    string s;
    int lastChar;
    int counter;
    
    printf("Please, give me an alphabetical key:\n");
    k = GetString(); 
        //check if k is  alphabetical
        for ( int i = 0; i < strlen(k); i++) {
            if (!isalpha(k[i])) {
             printf("The unappropriate key!\n"); 
             return 1;  
            }
        }
        // check if k !=0

        // check if s !=0
        
    printf("Please, give me a string:\n");
    s = GetString();
    for (int i = 0, j = strlen(s); i < j; i++) { 
    // s is alphabetic
        if (isalpha(s[i])) {
            //counter
            counter = lastChar % strlen(k);
                //if S is lowercase
                if (islower(s[i])){
                        s[i] = ('a' + (s[i] - 'a' + k[counter]) % 26);
                        printf("%c", s[i]);
                    }
                //if S is uppercase
                if (isupper(s[i])){
                        s[i] = ('A' + (s[i] - 'A' + k[counter]) % 26);
                        printf("%c", s[i]);
                    }
                lastChar++;
        }
    // s isn`t alphabetic
        else {   
            printf("%c", s[i]);
        }
    }
    printf("\n"); 
    return 0; 

}
