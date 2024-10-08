/*   ch10_8.c                   */
#include <stdio.h>
#include <stdlib.h>
#define  MAX(a,b) ( a > b ) ? a : b
int main()
{
    int x, y;

    printf("請輸入 2 個值 : ");
    scanf("%d %d",&x, &y);
    printf("較大值 = %d\n",MAX(x,y));
    system("pause");
    return 0;
}



