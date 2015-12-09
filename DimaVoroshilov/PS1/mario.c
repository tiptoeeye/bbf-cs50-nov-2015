// mario pyramid

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do 
    {
        printf("Input a positive integer not greater than 23\n");
        n = GetInt();
    }
    while (n < 1 || n > 23);
               
    printf("height: %i\n", n);
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n-i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i+1; j++)
        {
            printf("#");
        }
        printf("\n");    
    }
}

