/*   ch9_30_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int str_len(char s[]);	/* ��ƭ쫬�ŧi */ 
int str_len(char s[])
{
    int i = 0;          /* �]�w�r������ܼ� */ 

    while ( s[i] != '\0' )
       i++;
    return i;
}
int main()
{
    char str[80];
    int  len;

    printf("�п�J�r�� : ");
    scanf("%s", &str);
    len = str_len(str);
    printf("�r�� ���� : %d\n",len);
    system("pause");
    return 0;
}
