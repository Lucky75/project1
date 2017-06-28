/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"
#include <cs50.h>
#include <string.h>       
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>    

typedef struct node 
    {
        char word [LENGTH+1];
        struct node* next;
    }
    node;

unsigned int summa = 0;
node* hashtable [27][27];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    char tempword [LENGTH+1];
strcpy(tempword, word);
  for(int i = 0; i < strlen(tempword); i++)
   {
   if(tempword[i]<97&&tempword[i]>64)
   tempword[i] = tempword[i] + (97-65);
    }                                    // выбираем, в каком ведерке будем искать


        int vedro;  
        int vederko;
                            //определяем номер ведра по первой букве 
        if (tempword[0] > 95)
         vedro = tempword[0]-97;
        else vedro = 0;
        
        if (tempword[1] > 95)       //и номер ведерка по второй букве
        vederko = tempword[1]-97;
        else
        vederko=0;                  // на случай отсутствия второй буквы или апострофа
        
            //проверяем наличие слова в нашей хэштаблице
        node* cursor = hashtable[vedro][vederko];
        while(cursor!=NULL)   
        {
           //printf("%s, %s,\n",tempword, cursor -> word);
            
            if (strcmp(tempword, cursor -> word) == 0)
            return true;
        
            
            else
            cursor = cursor -> next;        
        
            
        }
       // if (cursor==NULL)
        return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
   FILE* ofile = fopen(dictionary, "r");
   if (ofile == NULL)
   {
       printf("ниче не получилось");
       return false;
   }
        char tempword [LENGTH+1];
        while((fscanf(ofile, "%s", tempword)) != EOF)
        {
            int vedro;  
            int vederko;
                                //определяем номер ведра по первой букве 
            if (tempword[0] > 95)
            vedro = tempword[0]-97;
            else
            vedro = tempword[0]-65;
            
            if (tempword[1] > 95)       //и номер ведерка по второй букве
            vederko = tempword[1]-97;
            else if (tempword[1] > 64)
            vederko = tempword[1]-65;
            else
            vederko=0;                  // на случай отсутствия второй буквы или апострофа
            
            
            //суем элемент в нужное ведро
            node* new_node = malloc(sizeof(node));  // создали новый узел
            strcpy(new_node->word, tempword);        //скопировали в него значение
                new_node-> next = hashtable[vedro][vederko];  //ставим его в нужное ведро
                hashtable[vedro][vederko] = new_node;      
            
            summa++;
           // if (vedro==0&&vederko==1)
            //printf("%s,%u \n",new_node->word, summa);        //new_node->word);
        }
    fclose (ofile);    
                    // проверка на заполнение хэштаблицы
 /*
node* cursor = hashtable[0][2];
while(cursor!=NULL)   
{
    printf("%s,\n",cursor->word);
    cursor = cursor -> next;        
}
*/ // проверка прошла, хэштаблица двухмерного массива из узлов создана
    
    if(summa>0)
    return true;
    else
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return summa;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < 27; i++)
    {
        for(int j = 0; j < 27; j++)
        {
            node* cursor = hashtable[i][j];
            while(cursor!=NULL)   
            {
                node* tempnode = cursor;
                cursor = cursor -> next;        
                free(tempnode);
            }
        }
    }
    return true;// TODO
//    return false;
}
