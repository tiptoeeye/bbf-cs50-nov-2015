// mario pyramid

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // ask user to input a number
    int n;
    do 
    {
        printf("Height: ");
        n = GetInt();
    }
    while (n < 0 || n > 23);
              
    // building a pyramid   
    for (int i = 1; i <= n; i++) 
    {
        // left-side
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        
        printf("  ");
        
        // right-side
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");    
    }
}

