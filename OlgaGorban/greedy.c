#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) {
    float s;
    int count = 0;
    do {
        printf("How much change do You own? Please, write the sum in right format (where $7.25 is 7.25))\n");
        s = GetFloat();
    }
    while (s<=0.00);
    printf ("Thanks!\n");
    
    int cents = roundf((s * 100.00));
    
    while (cents >= 25){
        cents -= 25;
        count++;
    }
    while (cents >= 10){
        cents -= 10;
        count++;
    }
    while (cents >= 5){
        cents -= 5;
        count++;
    }
    while (cents >= 1){
        cents -= 1;
        count++;
    }

printf("%d\n", count);
}
    