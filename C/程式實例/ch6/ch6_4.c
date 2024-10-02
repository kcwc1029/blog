/*   ch6_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum = 0;
    int i = 1;

    printf(" i       Á`©M   \n");
    printf("----------------\n"); 
    for ( i ; i <= 9; i++ )
    {
       sum += i;
       printf(" %d        %d\n",i,sum);
    }   
    system("pause");
    return 0;
}


