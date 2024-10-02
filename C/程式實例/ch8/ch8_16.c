/*   ch8_16.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[] = "台灣科技大學";
    char str2[] = "明志科技大學是台灣頂尖科技大學";

    puts("呼叫 strcpy 前");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    strncpy(str1,str2,4);
    puts("呼叫 strcpy 第 1 次後");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    strncpy(str1,str2,60);
    puts("呼叫 strcpy 第 2 次後");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    system("pause");
    return 0;
}


