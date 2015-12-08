#include <stdio.h>

int main(int argc, char **argv)
{
    int i = GetInt();
    
    for (int j=1; j<=i; j++)
    {
    for (int n=j; n<i; n++)
    {
        printf(" ");
    }
    for (int k=i+1; k>0; k--)
    {
        printf("#");
    } 
    printf("\n");
    }
  
    return 0;
    }

