#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    printf ("Input height:\n");
    
    do
    {
        n = GetInt();
    }
    while (n<=0 || n > 23);
    
    for (int i = 0; i < n; i++)
    { 
        for (int k = 0; k < n-i; k++)
        {
            printf(" ");
        }
        for (int m = 0; m < i; m++)
        {
            printf("#");
        }
        printf("#\n");
    }
    
}