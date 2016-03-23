/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

#define LIMIT 65536

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int min, int max)
{
    // TODO: implement a searching algorithm
    
    if (max < min) {
        return false;
    }
    else {
        int midpoint = (min + max)/2;
        
        if (values[midpoint] < value) {
            return search(value, values, midpoint + 1, max);
        }
        else if (values[midpoint] > value) {
            return search(value, values, min, midpoint - 1);
        }
        else {
            return true;
        }
    }
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm
    int count[LIMIT];
    for (int i = 0; i <= LIMIT; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[values[i]] += 1;
    }
    int b = 0;
    for (int i = 0; i < LIMIT; i++) {
        for (int j = 0; j < count[i]; j++) {
            values[b] = i;
            b++;
        }
    }
    return;
}

