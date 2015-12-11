// credit card validation

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // ask user to input a card number
    printf("Number: ");
    long long n = GetLongLong();
    
    // check for non-reasonable values
    int len = floor(log10(n)) + 1;
    if (len <= 12 || len == 14 || len >= 17)
    {
        printf("INVALID\n");
        return 0;
    }
   
    // long long to array transformation
    int card[len];
    for (int i = 0; i < len; i++)
    {
        card[i] = (int) (n / pow(10, len - i - 1));
        n -= pow(10, len - i - 1) * card[i];
    }
    
    // Hans Peter Luhn algorithm check_sum
    int check_sum = 0;
    // odd numbers starting from end
    for (int i = 0; i < len; i += 2)
    {
        check_sum += card[len - 1 - i];
    } 
    
    // even numbers starting from end
    for (int i = 0; i < len; i += 2)
    {
        if (card[len - 2 - i] * 2 >= 10)
        {
            check_sum += (card[len - 2 - i] * 2) % 10 + 1; 
        }
        else 
        {
            check_sum += card[len - 2 - i] * 2;
        } 
    }   
    if (check_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // card type identification
    if ((len == 13 || len == 16) && card[0] == 4)
    {
        printf("VISA\n");
    }
    else if (len == 15 && card[0] == 3 && (card[1] == 4 || card[1] == 7))
    {
        printf("AMEX\n");
    }
    else if (len == 16 && card[0] == 5 && card[1] != 0 && card[1] <= 5)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
 }


