/*   ch6_31.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i;
    int count = 1;
    int ans;
    
    srand(time(NULL));
    ans = rand() % 10 + 1; 		/* 設定欲猜數字 */
    while ( 1 )
    {
        printf("輸入欲猜數字 : ");
        scanf("%d",&i);
        if ( i > ans )
	        printf("請猜小一點!\n");
	    else if ( i < ans )
		    printf("請猜大一點!\n");
		else    
	        break;
       count++;
    }
    printf("花 %d 次猜對 \n",count);
    system("pause");
    return 0;
}


