/*   ch3_22.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[10];
    
    printf("請輸入你的名字 \n==>");
    scanf("%s", name);
    printf("\n");
    printf("%s 歡迎進入系統 \n", name);
    
    system("pause");
    return 0;
}


