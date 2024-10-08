/*   ch5_6.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x, y;

    printf("請輸入任意兩個整數值 ==> ");
    scanf("%d %d",&x, &y);
    if ( x > y )
       printf("%d 是較大值 \n",x);
    else
       printf("%d 是較大值 \n",y);
    system("pause");
    return 0;   
}


