#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int bukva=0; //считалка номера буквы

    // функция шифрования
void shifr(char c, int razmer, string key)
    {
        int ikey ; // порядковый номер буквы ключа (алфавитный)
        if(key[bukva]>96) //для строчных букв
        ikey = key[bukva]-97;
        else             //для заглавных
        ikey = key[bukva]-65;
        
        
        
        int as = c-razmer;       //из аски в алфавитную нумерацию
        as = (as + ikey) % 26;   //шифруем - прибавляем ключ
        as += razmer;               // возвращаем значение аски
        char xs = (char) as;    //
        printf("%c", xs);  // вывод на экран
        
        if(bukva<strlen(key)-1)  // переключаем букву ключа на следующую
        bukva++;
        else 
        bukva=0;
    }   

int main(int argc, char* argv[])
{
    //проверка на ввод второго аргумента
    if (argc != 2)
   { printf("Usage: ./caesar k\n");
    return 1;
   }
        //берем ключ из аргумента командной строки
        string key=argv[1];
        
    //проверка на ввод аргумента алфавитного характера
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i]<65||key[i]>122||(key[i]>90&&key[i]<97))
   { printf("Usage: ./caesar k\n");
    return 1;
   }    
    }
    
        //считываем строку для шифрования
        string s = GetString();
        int len = strlen(s);
    
        int big = 65;
        int small = 97;
    
        //шифруем по символу
        for(int i = 0; i < len; i++)
        {
    
            //заглавные буквы
            if (big <= s[i] && s[i] < big+26)
            {
                shifr(s[i], big, key);
            }
    
    
            //строчные буквы
            else if (small <= s[i] && s[i] < small+26)
            {
              shifr(s[i], small, key);
            }
    
        
            //другие символы оставляем, как есть
            else 
            printf("%c", s[i]);

        }
    printf("\n");
}


