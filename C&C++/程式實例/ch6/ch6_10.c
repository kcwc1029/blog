/*   ch6_10.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,sum;

    i = 1;
    sum = 0;
    while ( i <= 10 )
       sum += i++;
    printf("Á`©M = %d \n",sum);
    system("pause");
    return 0;
}


