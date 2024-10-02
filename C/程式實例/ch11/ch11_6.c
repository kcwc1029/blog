/*   ch11_6.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    int *ptr;
    
    x = 10;
    ptr = &x;  
    printf("變數 x 的值 = %d\n", x);
    printf("變數 x 的值 = %d\n", *&x);    
    system("pause");
    return 0;
}


