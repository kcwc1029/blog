/*   ch6_26.c                          */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,rnd;

    srand(time(NULL)); 			/* 種子值 */
    for ( i = 1; i <= 5; i++ )
    {    	 
        rnd = rand();
	    printf("隨機數 %d = %d\n",i,rnd);
    }
    system("pause");
    return 0;
}


