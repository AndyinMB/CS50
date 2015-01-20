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

/**
 * Returns true if value is in array of n values, else false.
 */

 
bool search(int value, int values[], int n)
{
    if(value < 0)
    {
        return 1;
    }
    int first = 0;
    int last = n-1;
    int middle = (first+last)/2;
    
    while (first <= last)
    {
        if (value == values[middle])
        {
            
            return true;
        }
        else if (value > values[middle])
        {
            first = middle + 1;
            middle = (first + last) / 2;
        }    
        else
        {
            last = middle - 1;
        }    
        middle = (first + last) / 2;
            
    }
    
    return false; 
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n; i++)
    {
        int smallest = values[i];
        int smallest_location = i;
            
        for (int j = i+1; j < n; j++)
        {
            if (smallest > values[j])
            {
                smallest = values[j];
                smallest_location = j;
                
            }
        }    
        values[smallest_location] = values[i];
        values[i] = smallest;
        
    }     
    return;
}
