/*   ch8_10.c                 */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[80] = "���Ӭ�ޤj��";
    char str2[80] = "�O�x�W���y��ޤj��";

    printf("��X�r��p�U \n");
    strcat(str1,str2);
    puts(str1);
    system("pause");
    return 0;
}


