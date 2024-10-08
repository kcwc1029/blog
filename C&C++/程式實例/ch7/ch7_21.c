/*   ch7_21.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int fib[10],i;

    fib[0] = 0;
    fib[1] = 1;
    for ( i = 2; i <= 9; i++ )
       fib[i] = fib[i-1] + fib[i-2];
    printf("fibonacci 數列數字如下 \n");
    for ( i = 0; i <= 9; i++ )
       printf("%3d",fib[i]);
	printf("\n");
	system("pause");
	return 0;
}


