#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


    // функция шифрования
void shifr(char c, int razmer, int key)
    {
        int as = c-razmer;       //из аски в алфавитную нумерацию
        as = (as + key) % 26;   //шифруем - прибавляем ключ
        as += razmer;               // возвращаем значение аски
        char xs = (char) as;    //
        printf("%c", xs);        // вывод на экран

    }   

int main(int argc, char* argv[])
{
    //проверка на ввод второго аргумента
    if (argc != 2)
   { printf("Usage: ./caesar k\n");
    return 0;
   }
        //берем ключ из аргумента командной строки
        int key = atoi(argv[1]);
    
    if (key < 1 || key > 26)
   return 0;
    
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
    
}


