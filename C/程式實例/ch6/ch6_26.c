/*   ch6_26.c                          */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,rnd;

    srand(time(NULL)); 			/* �ؤl�� */
    for ( i = 1; i <= 5; i++ )
    {    	 
        rnd = rand();
	    printf("�H���� %d = %d\n",i,rnd);
    }
    system("pause");
    return 0;
}


