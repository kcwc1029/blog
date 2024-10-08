/*   ch9_37.c                  */
#include <stdio.h>
#include <stdlib.h>
int gcd(int, int);
int main()
{
    int x, y;
    int gc;

    printf("請輸入 2 個正整數 \n==> ");
    scanf("%d %d",&x,&y);
    gc = gcd(x,y);
    printf("最大公約數是 %d \n",gc);
    system("pause");
    return 0;
}
int gcd(int x, int y)
{
	return (y == 0) ? x : gcd(y, x % y);
}


