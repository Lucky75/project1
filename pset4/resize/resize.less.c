/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int mnoz = atoi(argv[1]);
    
    //проверка на меньше 100
    if (mnoz>100)
    return 1;
    
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
//здесь надо написать не просто магию, а настоящее чудо
// теперь здесь пробуем увеличить ширину и высоту на коэффициент //получилось, оставляем
// запоминаем старые значения ширины и высоты

int oldWidth = bi.biWidth;
int oldHeight = bi.biHeight;

bi.biHeight*=(mnoz);

int xx = (4-((oldWidth*sizeof(RGBTRIPLE)) % 4))%4; 
    
bi.biWidth*=(mnoz);
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

bi.biSizeImage = abs(bi.biHeight*bi.biWidth)*sizeof(RGBTRIPLE)+abs(padding*bi.biHeight);
bf.bfSize = bi.biSizeImage + 54;

// write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
// записали данные нового файла (размеры)
    
    
    // determine padding for scanlines

    // iterate over infile's scanlines
// тут надо что-то сделать, чтоб каждая считанная строка записывалась коэффициент раз
// меняем значения новых на старые
    for (int i = 0; i < abs(oldHeight); i++)
    {
        for (int l = 0; l < mnoz; l++)            // вот оно ,тут итерируем одну и ту же строку коэффициент раз
        {
        // iterate over pixels in scanline  // а тут меняем на старый ширину
        for (int j = 0; j < oldWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            
            //попробуем каждый пиксель записать коэффициент раз
            for (int k = 0; k<mnoz; k++)
            {
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }
        //теперь, когда закончилась ширина 
        // skip over padding in infile
						fseek(inptr, xx, SEEK_CUR);  // еле разобрался. после окончания Width мы пропускаем хх байтов с SEEK_CUR позиции
                                                    // таким образом перескакиваем выравнивание, если оно есть
						// then add it to outfile
						for (int m = 0; m < padding; m++)  // а здесь мы в конце строки нового файла, если надо, вставляем  
								fputc(0x00, outptr);        // вот эти пустые пиксели  - выравнивание

						fseek(inptr, -(oldWidth * 3 + xx ), SEEK_CUR); // и затем возвращаемся в начало строки, чтоб еще коэффициент раз повторить ее
        }
        
        // теперь, когда закончились все строки, мы  после последней команды в цикле(строка 129)  оказались в начале последней строки
        // skip over padding, if any
        fseek(inptr, oldWidth *3 + xx, SEEK_CUR);   // и тут мы перескакиваем через эту строку в конец.
  
  }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
