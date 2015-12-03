/*
 * conditions-1.
 
 * David J. Mala
 * malan@harvard.ed
 
 * Tells user if his or her input is positive or negative
 
 * Demonstrates use of if-else if-else construct
 */
 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	int n;
    printf("I'd like an integer please: ");
    n = GetInt();



    /* analyze user's inpu */
    if (n > 0)
    
        printf("You picked a positive number!\n");
    
    else if (n == 0)
    
        printf("You picked zero!\n");
    
    else
    
        printf("You picked a negative number!\n");
    
} 

