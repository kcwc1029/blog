/*   ch6_8.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;

    printf(" \n");    /* �̤W��d�ť� */ 
    for ( i = 1; i <= 10; i++ )
    {
       for ( j = 1; j <= i; j++ )
	      printf("%c%c",97,97);
       printf("\n");
    }
    system("pause");
    return 0;
}


