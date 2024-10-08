/*   ch6_29.c                          */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main()
{
    int i,rnd;

    srand(time(NULL)); 			/* 種子值 */
    for ( i = 1; i <= 5; i++ )
    {    	 
        rnd = rand();
        sleep(1);               /* 休息 1 秒 */ 
	    printf("隨機數 %d = %d\n",i,rnd);
    }
    system("pause");
    return 0;
}


