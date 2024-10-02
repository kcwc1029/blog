/*   ch6_33.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x = 1000000;
    int i;
    double pi = 0.0;

    for ( i = 1; i <= x; i++ )
	{
	    pi += 4*(pow(-1,(i+1)) / (2*i-1));
		if (i % 100000 == 0)
		    printf("·í i = %7d ®É PI = %20.19lf\n",i,pi);   	
	} 
    system("pause");
    return 0;
}


