/*   ch8_9.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[80] = "���Ӭ�ޤj��";

    printf("�r���X�p�U \n");
    puts(str);
    puts(str+4);
    puts(&str[4]);
    system("pause");
    return 0;
}


