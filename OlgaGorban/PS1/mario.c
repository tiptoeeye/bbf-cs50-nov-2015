#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;
    do {
        printf("Please give me a non-negative number no greater than 23!\n");
        n = GetInt();
    }
    while (n>23 || n<0);
    printf("Thanks!\n");
     
            for (int i=1; i<=n; i++) {
                for (int spaces = 0; spaces <= n-i ; spaces ++){   
                    printf(" ");
                }
                for (int hashes = 1; hashes <= i+1; hashes ++) {
                    printf("#");
                }
                printf("\n");
            }
    
}