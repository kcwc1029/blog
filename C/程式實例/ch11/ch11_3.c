/*   ch11_3.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 6;
    int *ptr;
    
    ptr = &x;
    printf("%d\n", x);
    printf("%d\n", *ptr);
    system("pause");
    return 0;
}


