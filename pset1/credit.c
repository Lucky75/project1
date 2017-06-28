#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //получить номер кода
    long long number = get_long_long();
    
    
    //проверить кол-во цифр
    int kol = 0;
    long long use = number;
    
    do 
    {
        use/=10;
        kol++;
    }
    while (use!=0);
    
    if (kol!=15&&kol!=13&&kol!=16)
   return 1;
    
    //printf("%d", kol);
    
    //посчитать по формуле
    int mas [kol];
    use = number;
    int sum = 0;
    for (int i = kol-1; i>-1; i--)
    {
        mas[i] = use % 10;
        use /= 10;
    if ((i+1)%2 == 0)
    mas[i] = (mas[i]*2)%10+((mas[i]*2)/10);
   // printf("%d", mas [i]);
    sum += mas[i];
    }
    if (sum!=60)
    {
    printf ("карта не существует\n");
    return 0;
    }
    
    //возвращаем в массив значения карты
    use = number;
    for (int i = kol-1; i>-1; i--)
    {
        mas[i] = use % 10;
        use /= 10;
    //    printf("%d", mas [i]);
    }
    
    //если норм, определить, что за карта
    if ( (kol==15) && (mas[0]==3) && ((mas[1]==7) || (mas[1]==4)))
    printf ("American Express\n");
   
    else if ( (kol==16) && (mas[0]==5) && ((mas[1]>0) && (mas[1]<6)))
    printf ("MasterCard\n");
    
    else if ( ((kol==16)||(kol==13)) && (mas[0]==4) )
    printf ("Visa \n");
    
    else 
    printf ("карта не существует\n");
    
}