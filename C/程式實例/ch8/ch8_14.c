/*   ch8_14.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[] = "Introduction to C";
    char str2[] = "Published by Deepmind";

    puts("�� 1 ���r�굲�X");
    strncat(str1,str2,4);
    puts(str1);
    puts("�� 2 ���r�굲�X");
    strncat(str1,str2,50);
    puts(str1);
    system("pause");
    return 0;
}


