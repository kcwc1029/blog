/*   ch9_6.c                   */
#include <stdio.h>
#include <stdlib.h>
void larger(int a, int b)  
{
    if ( a < b )
       printf("較大值是 %d \n",b);
    else if ( a > b )
       printf("較大值是 %d \n",a);
    else
       printf("兩數值相等 \n");
    return;
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


