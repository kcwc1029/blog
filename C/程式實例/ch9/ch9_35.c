/*   ch9_35.c                   */
#include <stdio.h>
#include <stdlib.h>
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return (fib(n-1)+fib(n-2));
}
int main()
{
    int i;
    int max = 10; 		/* 計算前10個費氏數列 */ 
    printf("費氏數列 1 - 10 如下 :\n");
    for (i = 1; i <= max; i++)
    	printf("fib[%d] = %d\n", i, fib(i));
    system("pause");
    return 0;
}


