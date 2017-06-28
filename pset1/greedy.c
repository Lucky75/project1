#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int count=0;
int coins;
void x(int y)
{
    while (coins>=y)
    {
    coins-=y;
    count++;
    }
}

int main(void)
{
    float fcoins;
    
        do 
        {
            printf("O hai! How much change is owed?\n");
            fcoins = GetFloat();
        }
        while (fcoins<0);
    
    fcoins*=100;
    coins = (int)fcoins; 
    
    x(25);
    x(10);
    x(5);
    x(1);
    
    printf("%d\n", count);
     system ("pause");
}