/*   ch9_18.c                  */
#include <stdio.h>
#include <stdlib.h>
void palindrome(int n);
int main()
{
    int i = 5;     /* 設定輸入 5 個字元 */ 
    
    printf("請輸入含 5 個字元的字串\n");
    palindrome(i);
    printf("\n");
    system("pause");
    return 0;
}
/* 讀取字元和反向輸出字元 */ 
void palindrome(int n)
{
    char next;

    if ( n <= 1 ) 	/* 讀到最後ㄧ個字元此條件會成立  */ 
    {
       next = getche();
       printf("\n");
       putchar(next);
    }
    else
    {
       next = getche();   /* 讀字元   */ 
       palindrome(n-1);    /* 呼叫自己 */ 
       putchar(next);
    }
}


