/*   ch9_32.c                   */
#include <stdio.h>
#include <stdlib.h>
int sum(int n)
{
    int i, sum;

    sum = 0;
    for ( i = 1; i <= n; i++ )
       sum += i;
    return sum;
}
int main()
{
    int n;

    printf("請輸入系列加總值 : ");
    scanf("%d",&n);
    printf("從 1 加到 %d = %d\n",n,sum(n));
    system("pause");
    return 0;
}


