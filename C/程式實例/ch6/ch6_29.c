/*   ch6_29.c                          */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main()
{
    int i,rnd;

    srand(time(NULL)); 			/* �ؤl�� */
    for ( i = 1; i <= 5; i++ )
    {    	 
        rnd = rand();
        sleep(1);               /* �� 1 �� */ 
	    printf("�H���� %d = %d\n",i,rnd);
    }
    system("pause");
    return 0;
}


