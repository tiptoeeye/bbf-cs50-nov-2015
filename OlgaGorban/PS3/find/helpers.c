/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
void swap (int* a, int*b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
} 
 
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    if (value < 0)
        return false;
    else
    {
        int max = n-1;
        int min = 0;
        
        
        while (max>=min)
        {
            int middle = (max + min)/2;
            if(values[middle]==value)
                return true;
            else if (values[middle]>value)
                max = middle - 1;
            else
                min = middle + 1;     
        }
        return false;
    }
}

/**
 * Sorts array of n values.
 */
 
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i=1; i<n; i++)
    {
        int j = i;
        while (values[j] < values [j-1] && j>0)  
        {
            swap(&values[j], &values[j-1]);
            j--;
        }    
    }
    return;  
}
