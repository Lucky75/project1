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
        
        bool isword;
        struct node* children[27];
    }
    node;

node* root;
unsigned int summa = 0;

void recursivfree (node* head)
{
    
        for (int i = 0; i < 27; i++)
        {
            if (head->children[i]==NULL)
            {
                recursivfree(head->children[i]);
            }
        if(head!=root)
        {free(head);}
        }
        
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    char tempword [LENGTH+1];
strcpy(tempword, word);
  for(int i = 0; i < strlen(tempword); i++)  // уменьшаем регистр
   {
   if(tempword[i]<97&&tempword[i]>64)
   tempword[i] = tempword[i] + (97-65);
    }  

node* head = malloc(sizeof(node));
            head = root;
            
        for(int i = 0; i < strlen(tempword); i++)
            {
                int num = tempword[i]-96;
                
                if(num<0)
                    num = 0;
                
                if(head -> children[num] == NULL)
                    return false;
                
                head = head -> children[num];
                
                if (i==strlen(tempword)-1) 
                    return head -> isword;
                
            }
       
      return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    root = malloc(sizeof(node));
   FILE* ofile = fopen(dictionary, "r");
   if (ofile == NULL)
   {
       printf("ниче не получилось");
       return false;
   }
   
        char tempword [LENGTH+1];
        while((fscanf(ofile, "%s", tempword)) != EOF)
        {
            node* head = malloc(sizeof(node));
            head = root;
            
        for(int i = 0; i < strlen(tempword); i++)
            {
                
                int num = tempword[i]-96;
                if(num<0)
                {
                    num = 0;
                }
                
                if(head -> children[num] == NULL)
                {
                    node* new_node = malloc(sizeof(node));
                    head -> children[num] = new_node;
                    new_node -> isword = false;
                }
                
                head = head -> children[num];
                
                if (i==strlen(tempword)-1)
                head -> isword = true;
            }
                       
        summa++;
        }
    fclose (ofile);    
    
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
    

    
    recursivfree(root);
           
    return true;// TODO
}
