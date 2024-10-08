/*   ch15_1.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    printf("請輸入任意字元 : "); 
    scanf("%c", &ch);
    if ( isalnum(ch) )
    	printf("%c 是屬於英文字母或阿拉伯數字\n", ch);
    else
    	printf("%c 不屬於英文字母或阿拉伯數字\n", ch);
    system("pause");
    return 0;
}


