/*   ch6_27.c                          */
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
    int i,rnd;

    srand(time(NULL)); 			/* �ؤl�� */
    for ( i = 1; i <= 10; i++ )
    {    	 
        rnd = rand() % 6 + 1;
	    printf("��l�� %2d = %d\n",i,rnd);
    }
    system("pause");
    return 0;
}


