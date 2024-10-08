/*   ch9_30_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int str_len(char s[]);	/* 函數原型宣告 */ 
int str_len(char s[])
{
    int i = 0;          /* 設定字串長度變數 */ 

    while ( s[i] != '\0' )
       i++;
    return i;
}
int main()
{
    char str[80];
    int  len;

    printf("請輸入字串 : ");
    scanf("%s", &str);
    len = str_len(str);
    printf("字串 長度 : %d\n",len);
    system("pause");
    return 0;
}
