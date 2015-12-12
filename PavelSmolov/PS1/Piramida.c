#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Plese enter the int in the following range 0...23:\n");
    int n;
    do 
    {
        n = GetInt();
    } while ( n <= 0 || n > 23);
    
    printf("You've picked number:%i\nYour output:\n\n", n);

    for (int i = 0; i < n; i++) //rows
    {
        for (int j = 0; j < n - i; j++) // iterate with spaces
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) // iterate with hashes
        {
            printf("#");
        }
        printf( "#\n" );//just to fill in last missing column 
    }
    
}
