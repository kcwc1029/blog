/*   ch6_36.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    while ( 1 )
    {
       printf("請輸入任意值 ==> ");
       scanf("%d",&i);
       if ( i < 0 )
          i = -i;
       printf("絕對值是 %d \n",i);
    }
    system("pause");
    return 0;
}


