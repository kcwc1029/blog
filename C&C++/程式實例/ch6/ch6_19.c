/*   ch6_19.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int count = 1;
    while ( 1 )
    {
       printf("輸入欲猜數字 : ");
       scanf("%d",&i);
       if ( i == 5 )   /* 設定欲猜數字 */ 
	      break;
       count++;
    }
    printf("花 %d 次猜對 \n",count);
    system("pause");
    return 0;
}


