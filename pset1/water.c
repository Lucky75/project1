#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int min, bot;
    min = GetInt();
    bot = min*12;
    printf("Minutes: %d \n", min);
    printf("Bottles: %d \n", bot);
    system ("pause");
}