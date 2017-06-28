/**
 * helpers.c
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
    int step1=n/2;
    int step2=n/2;
    
    
while((0<=step1)&&(step1<n)&&(step2>0))
{
if(value==values[step1])
return true;

step2+=1;
step2/=2;

if (value<values[step1])
step1=step1-step2;
else step1=step1+step2;
if (value==values[step1])
return true;

if (step2==1)
return false;


}
//if ((0>step1)||(step1>n))
//{step1=-1;}
    // TODO: implement a searching algorithm
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if (values[j]>values[j+1])
            {
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1]=temp;
            }
        }
    }
        // TODO: implement an O(n^2) sorting algorithm
    return ;//values[];
}
