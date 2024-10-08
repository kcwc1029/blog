/*   ch5_10.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c;

    printf("請輸入任意 2 數字 ==> ");
    scanf("%d%d",&a,&b);
    c = ( a > b ) ? a : b;
    printf("較大值是 %d \n",c);
    system("pause");
    return 0;
}


