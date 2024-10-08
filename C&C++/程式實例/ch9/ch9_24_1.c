/*   ch9_24_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    register  int  i; 	/* 宣告 register 變數 */ 
    int  tmp = 0;

    for ( i = 1; i <= 100; i++ )
       tmp += i;
    printf("總和 = %d\n",tmp);
    system("pause");
    return 0;
}


