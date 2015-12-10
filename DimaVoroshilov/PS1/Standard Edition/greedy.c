// greedy algorithm program

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(int argc, string argv[])
{
    // ask user to input a change
    float change;
    do 
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    }
    while (change < 0);
    
    // converting dollars to cents
    int cents = (int) round(change * 100);
    
    int coins = 0;
    
    // counting the required number of 25c coins
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }
    
    // counting the required number of 10c coins
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    
    // counting the required number of 5c coins
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    
    // counting the required number of 1c coins
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    
    printf("%i\n", coins);
}
