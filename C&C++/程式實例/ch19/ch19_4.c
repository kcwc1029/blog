/*   ch19_4.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 35;
    b = a & 7;
    printf("a & b (10 進位) = %d \n",b);
    b &= 7;
    printf("a & b (10 進位) = %d \n",b);
    system("pause");
    return 0;
}


