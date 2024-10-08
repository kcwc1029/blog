/*   ch6_28.c                          */
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
    int i;
    float rnd;

    srand(time(NULL)); 			/* ºØ¤l­È */
    for ( i = 1; i <= 10; i++ )
    {    	 
        rnd = (float )rand() / (RAND_MAX + 1);
	    printf("»ë¤l­È %2d = %f\n",i,rnd);
    }
    system("pause");
    return 0;
}


