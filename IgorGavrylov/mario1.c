#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;
    do 
    {
        printf("Please enter a positive number not greater than 23:\n");
        n = GetInt();
    }
    while (n<=0||n>23);
    printf("OK\n");

for (int i = 0; i<=n-1; i++)
    {
        for (int sp = 0; sp <=n-i; sp++)
        {
            printf(" ");
        }
        for (int hashes = 1; hashes<=i+1; hashes++)
        {
            printf("#");
        }
    printf("\n");
    }
}
