#include <stdio.h>
#include <cs50.h>
#include <math.h>

int FunChange(float money, float coint)
{
    int counter = 0;
    while(money >= coint)
    {
        counter++;
        money -= coint;
    }
    return counter;
}

int main(void)
{
    printf("Hi! How much change is owed? ");
    
    float change = GetFloat();
    while(change <= 0)
    {
        printf("Invalid input. Please try again.");
        change = GetFloat();
    }
    
    int x = 0; // is a counter that is our result!
    static float coins[] = {.25,.1,.05,.01};
    
    for(int i = 0; i < 4; i++ )
    {
        x += FunChange(change,coins[i]);
        change = fmodf(change, coins[i]);
    }
      
    printf("Total number of coins is: %i\n", x);
    return 0;
}
