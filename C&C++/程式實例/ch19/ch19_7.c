/*   ch19_7.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 7;
    b = ~a;
    printf("a 的 1 補數 ( 10 進位) = %d \n",b);
    printf("a 的 1 補數 ( 16 進位) = %x \n",b);
    system("pause");
    return 0;
}



