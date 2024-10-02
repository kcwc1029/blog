/*   ch6_32.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,tmp;

    printf("請輸入 2 個正整數 \n==> ");
    scanf("%d %d",&i,&j);
    while ( j != 0 )
    {
       tmp = i % j;
       i = j;
       j = tmp;
    }
    printf("最大公約數是 %d \n",i);
    system("pause");
    return 0;
}


