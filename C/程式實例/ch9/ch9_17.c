/*   ch9_17.c                  */
#include <stdio.h>
#include <stdlib.h>
int factriol(int n)
{
    int fact;                          

    if ( n == 0 )                    /* ²×¤î±ø¥ó   */ 
       fact = 1;
    else
       fact = n * factriol(n - 1);   /* »¼°j©I¥s   */ 
    return fact;
}
int main()
{
	int x = 3;
	
    printf("%d!  =  %d \n",x,factriol(x));
    x = 5;
    printf("%d!  =  %d \n",x,factriol(x));
    system("pause");
    return 0;   
}



