/*   ch6_25.c                          */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,rnd;

    srand(10); 			/* 種子值 */
    for ( i = 1; i <= 5; i++ )
    {    	 
        rnd = rand();
	    printf("隨機數 %d = %d\n",i,rnd);
    }
    system("pause");
    return 0;
}


