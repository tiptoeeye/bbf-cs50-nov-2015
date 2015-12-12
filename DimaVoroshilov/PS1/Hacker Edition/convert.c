// base10 to base2

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int base10;
    // ask user to input a base10 number
    do
    {
        printf("Please, insert a base10 non-negative number\n");
        base10 = GetInt();
    }
    while (base10 < 0);
    
    int power = (int) log2(base10);  
    
    // conversion
    unsigned long long base2 = 0; 
    while (power >= 0)
    {
        if (base10 / (int) pow(2, power))
        {
            base2 += (int) (base10 / ((int) pow(2, power))) * (unsigned long long) pow(10, power);
            base10 -= (int) pow(2, power);
        }
        power--;
    }
    
    // output of base2 number
    printf("base2: %llu\n", base2);
}    
