#include <stdio.h>
#include <cs50.h>
#include <math.h>

void greedy()
{

    // 0,25; 0.1, 0.05, 0.01
    
    printf("How much money would you like to change?\n");
    float moneyToChange = GetFloat();
    while(moneyToChange<=0)
    {
        printf("Invalid value! Try again!\n");
        moneyToChange = GetFloat();
    }
    
    
    int counter = 0;
    int globalCounter = 0;
    
    while(moneyToChange>=0.25)
    {
        counter++;
        moneyToChange = moneyToChange-0.25;
    }
    printf("25 cents count: %i\n", counter);

    counter = 0;
    globalCounter = globalCounter + counter;
    while(moneyToChange>=0.1)
    {
        counter++;
        moneyToChange = moneyToChange-0.1;
    }
    printf("10 cents count: %i\n", counter);
    
    printf("total coins count: %i\n", globalCounter);
    return 0;
}

