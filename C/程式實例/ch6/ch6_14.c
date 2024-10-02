/*   ch6_14.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,result;

    i = 1;
    while ( i <= 9 )
    {
       j = 1;
       while ( j <= 9 )
       {
			 result = i * j;
			 printf("%d*%d=%-3d\t",i,j++,result);
       }
       i++;
       printf("\n");
    }
    system("pause");
    return 0;
}


