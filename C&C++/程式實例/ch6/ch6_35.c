/*   ch6_35.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int sum = 0;
    int wheat;
    int i;
    for ( i = 0; i < 30; i++ )
    {
    	if ( i == 0 )
    		wheat = 1;
       	else
    	    wheat = (int) pow(2,i);
    	sum +=  wheat;	
	}
	printf("³Á²ÉÁ`¦@ = %d\n",sum);
    system("pause");
    return 0;
}


