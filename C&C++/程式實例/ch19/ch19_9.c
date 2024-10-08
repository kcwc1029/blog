/*   ch19_9.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 14;
    b = a >> 1;
    printf("位元右移 1 次 = %d \n",b);
    b = a >> 3;
    printf("位元右移 3 次 = %d \n",b);
    system("pause");
    return 0;
}


