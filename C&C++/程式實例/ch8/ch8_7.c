/*   ch8_7.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[80];
    char str2[80];

    printf("請輸入 2 個句子 \n");
    gets(str1);
    scanf("%s",str2);
    printf("字串 1 是 ===> %s\n",str1);
    printf("字串 2 是 ===> %s\n",str2);
    system("pause");
    return 0;
}


