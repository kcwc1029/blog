/*   ch8_16.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[] = "�x�W��ޤj��";
    char str2[] = "���Ӭ�ޤj�ǬO�x�W���y��ޤj��";

    puts("�I�s strcpy �e");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    strncpy(str1,str2,4);
    puts("�I�s strcpy �� 1 ����");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    strncpy(str1,str2,60);
    puts("�I�s strcpy �� 2 ����");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    system("pause");
    return 0;
}


