/*   ch6_18.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 1; i <= 100; i ++ )
    {
       printf("�j����� %d \n",i);
       if ( i >= 5 )
	      break;
    }
    system("pause");
    return 0;
}


