/*   ch6_23.c                          */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,rnd;

    for ( i = 1; i <= 5; i++ )
    {
        rnd = rand();
	    printf("ÀH¾÷¼Æ %d = %d\n",i,rnd);
    }
    system("pause");
    return 0;
}


