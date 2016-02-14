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

//#define result false;

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int min, int max)
{
    // TODO: implement a searching algorithm
    bool result = false;  
    
    if (max < min) {
        return false;
    }
    else {
        int midpoint = (min + max)/2;
        
        if (values[midpoint] < value) {
            search(value, values, midpoint + 1, max);
        }
        else if (values[midpoint] > value) {
            search(value, values, min, midpoint - 1);
        }
        else {
            result = true;
        }
    }
    
    return result;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int x;
    for (int i = 0; i < n -1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (values[j] < values[min]) {
                x = values[min];
                values[min] = values [j];
                values[j] = x;
            }
        }
        //swap
    }
    return;
}