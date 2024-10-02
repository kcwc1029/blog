/*   ch9_5.c                   */
#include <stdio.h>
#include <stdlib.h>
void larger(a, b)  /* 舊版宣告 */ 
int a, b;
{
    if ( a < b )
       printf("較大值是 %d \n",b);
    else if ( a > b )
       printf("較大值是 %d \n",a);
    else
       printf("兩數值相等 \n");
}
int main()
{
    int i,j;

    printf("請輸入兩數值 \n ==> ");
    scanf("%d %d",&i,&j);
    larger(i,j);
    system("pause");
    return 0;
}


