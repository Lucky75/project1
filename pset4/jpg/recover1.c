/**
 * Copies a BMP piece by piece, just because.
 */
#include <cs50.h>
#include <string.h>       
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    
          //проверка на второй аргумент
    if ((argc!=2)||(strcmp(argv[1], "card.raw") !=0 ))
    {
        printf( "Usage: ./recover card.raw\n");
        return 1;
    }
    

    char *infile = argv[1]; //называем входящий-исходящий
        //открываем файл карты с проверкой
   FILE* inf = fopen(infile, "r");
   if (inf == NULL)
    {
        fprintf(stderr, "Could not open \n");
        return 2;
    }

    //открываем новый буферный файл с проверкой
    FILE *outf ;//= fopen(outfile, "w"); 
   /*if (outf == NULL)
    {
        fclose(inf);
        fprintf(stderr, "Could not create \n");
        return 3;
    }
*/

    uint8_t tmp[512]; // создаем буфер по 512 байт
    int count = 0;              //считалка файлов
    //fseek (inf, 1024, SEEK_SET);
    while(fread(tmp, 512, 1, inf) > 0)//пока не закончится карта
    {
        fread(&tmp, sizeof(tmp), 1, inf); //начинаем считывать  по 512 байтов из карты памяти
        
        if ((tmp[0] == 0xff && tmp[1] == 0xd8 && tmp[2] == 0xff) && (tmp[3] == 0xe0 || tmp[3] == 0xe1))     // если первые четыре байта совпадают
        {  
            if(count!=0)
            fclose(outf); //закрываем старый файл
            count ++;   
          
            //и создаем его    
            char filename[8];
         //  printf("%s", filename);
           sprintf(filename, "%03d.jpg", count);
            char *outfile = filename;
             outf = fopen(outfile, "w");  //открываем новый файл для записи с проверкой
            if (outf == NULL)
            {
                fclose(inf);
                fprintf(stderr, "Could not create %s.\n", outfile);
                return 3;
            }           
        
        }
            if(count!=0)
            fwrite(&tmp, sizeof(tmp), 1, outf) ;  // и начинаем записывать эти 512 байт в новый файл или продолжаем в старый
            
    }
        
        fclose(outf); //закрываем последний файл
        fclose(inf); 
        
        //делаем проверку контрольной суммы
    // success
    return 0;
}