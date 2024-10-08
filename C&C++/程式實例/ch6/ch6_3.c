/*   ch6_3.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum = 0;
    int i = 1;

    for ( ; i <= 100; )
       sum += i++;
    printf("Á`©M = %d \n",sum);
    system("pause");
    return 0;
}


