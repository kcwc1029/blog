/*   ch6_21.c                          */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    sum = 0;
    for ( i = 2; i <= 100; i++ )
    {
       if ( ( i % 2 ) != 0 )
	      continue;
       sum += i;
    }
    printf("Á`©M¬O %d \n",sum);
    system("pause");
    return 0;
}


