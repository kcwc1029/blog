/*   ch19_5.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 32;
    b = a | 3;
    printf("a | b (10 �i��) = %d \n",b);
    b |= 7;
    printf("a | b (10 �i��) = %d \n",b);
    system("pause");
    return 0;
}


