#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    //������ ��� ������� �������� ���������...
    string s = get_string();
    if (s != NULL)
    {
        //������� ������ �������
        if (s[0] != ' ')
        printf("%c", toupper(s[0]));
        
        //������� ������ ����� ����� �������� � �������
        int n = strlen(s)-1;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == ' ' && s[i+1] != ' ')
            printf("%c", toupper(s[i+1]));
        }
        
        
    }
    
}