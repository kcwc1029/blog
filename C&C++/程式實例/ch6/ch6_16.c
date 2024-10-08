/*   ch6_16.c                     */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    i = 1;
    sum = 0;
    do
    {
       sum += i++;
    } while ( i <= 100 );
    printf("Á`©M = %d \n",sum);
    system("pause");
    return 0;
}


