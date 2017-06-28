#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int bukva=0; //�������� ������ �����

    // ������� ����������
void shifr(char c, int razmer, string key)
    {
        int ikey ; // ���������� ����� ����� ����� (����������)
        if(key[bukva]>96) //��� �������� ����
        ikey = key[bukva]-97;
        else             //��� ���������
        ikey = key[bukva]-65;
        
        
        
        int as = c-razmer;       //�� ���� � ���������� ���������
        as = (as + ikey) % 26;   //������� - ���������� ����
        as += razmer;               // ���������� �������� ����
        char xs = (char) as;    //
        printf("%c", xs);  // ����� �� �����
        
        if(bukva<strlen(key)-1)  // ����������� ����� ����� �� ���������
        bukva++;
        else 
        bukva=0;
    }   

int main(int argc, char* argv[])
{
    //�������� �� ���� ������� ���������
    if (argc != 2)
   { printf("Usage: ./caesar k\n");
    return 1;
   }
        //����� ���� �� ��������� ��������� ������
        string key=argv[1];
        
    //�������� �� ���� ��������� ����������� ���������
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i]<65||key[i]>122||(key[i]>90&&key[i]<97))
   { printf("Usage: ./caesar k\n");
    return 1;
   }    
    }
    
        //��������� ������ ��� ����������
        string s = GetString();
        int len = strlen(s);
    
        int big = 65;
        int small = 97;
    
        //������� �� �������
        for(int i = 0; i < len; i++)
        {
    
            //��������� �����
            if (big <= s[i] && s[i] < big+26)
            {
                shifr(s[i], big, key);
            }
    
    
            //�������� �����
            else if (small <= s[i] && s[i] < small+26)
            {
              shifr(s[i], small, key);
            }
    
        
            //������ ������� ���������, ��� ����
            else 
            printf("%c", s[i]);

        }
    printf("\n");
}


