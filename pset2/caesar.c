#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


    // ������� ����������
void shifr(char c, int razmer, int key)
    {
        int as = c-razmer;       //�� ���� � ���������� ���������
        as = (as + key) % 26;   //������� - ���������� ����
        as += razmer;               // ���������� �������� ����
        char xs = (char) as;    //
        printf("%c", xs);        // ����� �� �����

    }   

int main(int argc, char* argv[])
{
    //�������� �� ���� ������� ���������
    if (argc != 2)
   { printf("Usage: ./caesar k\n");
    return 0;
   }
        //����� ���� �� ��������� ��������� ������
        int key = atoi(argv[1]);
    
    if (key < 1 || key > 26)
   return 0;
    
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
    
}


