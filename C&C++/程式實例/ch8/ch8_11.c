/*   ch8_11.c                 */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "Borland C++ Introduction";
    char str2[] = "Visual C++ Introduction";
    int i;

    i = strcmp(str1,str2);
    if ( i == 0 )
       printf("�r��ۦP \n");
    else if ( i > 0 )
    {
       printf("�r�ꤣ�P \n");
       puts("str1 �r���Ȥj�� str2");
    }
    else
    {
       printf("�r�ꤣ�P \n");
       puts("str2 �r���Ȥj�� str1");
    }
    system("pause");
    return 0;
}


