#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int x;
    do
    {
    x=GetInt();
    }
    while (x<0||x>23);
    
    for (int i =0;i<x;i++)
    {
        for(int j=i+1;j<x;j++)
        {printf(" ");}
        
        for(int j=x-i;j<=x;j++)
        {printf("#");}
        
        printf("\n");
        
    }
	system ("pause");
}