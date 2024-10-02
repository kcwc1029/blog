/*   ch3_21.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch1, ch2;
    
    printf("請輸入 2 個字元 \n==>");
    ch1 = getch();
    ch2 = getch();
    printf("\n");
    printf("第 1 個字元是 \n==>");
    putchar(ch1);
    printf("\n");
    printf("第 2 個字元是 \n==>");
    putchar(ch2);
    printf("\n");
    system("pause");
    return 0;
}


