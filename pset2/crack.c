#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>

       char *crypt(const char *key, const char *salt);

       #define _GNU_SOURCE         /* See feature_test_macros(7) */
       #include <crypt.h>

      // char *crypt_r(const char *key, const char *salt, struct crypt_data *data);




int main(int argc, char* argv[])
{
    //проверка на ввод второго аргумента
    if (argc != 2)
   { printf("Usage: ./crack k\n");
    return 1;
   }
        //берем ключ из аргумента командной строки
        string key = argv[1];
    printf("%s", key);
    
    // вводим массив всех букв
    char all[52];
    for(int i = 0; i<26; i++)
    {
        all[i] = i+97;
    }
    for(int i = 0; i<26; i++)
    {
        all[i+26] = i+65;
    }
    //  for(int i = 0; i<52; i++)
    //  {
    //      printf("%c \n", all[i]);
    //  }
        
    int len = strlen(all)-26;
    char podbor[] = {'1','2','3','4','\0'};
    // подбираем пароли по букве
    string salt = "50";
    for(int i = 0; i < len; i++)
    {
        podbor[0] = all[i];
        string x = podbor;
        printf ("%s \n", x);
        
        for(int j = 0; j < len; j++)
        {
            podbor[1] = all[j];

            for(int k = 0; k < len; k++)
            {
                podbor[2] = all[k];

                for(int l = 0; l < len; l++)
                {
                    podbor[3] = all[l];
    
                    string cr = crypt(podbor, salt);
                    
                    if(strcmp(cr, key) == 0)  //проверка на совпадение вводимого хеша и хеша от нашего подбора
                    {
                    printf ("%s \n", podbor);
                    //printf (" %s \n", crypt(podbor, salt));
                    
                    return 0;
                        
                    }
                }
                
            }
            
        }
    }        

    
}


