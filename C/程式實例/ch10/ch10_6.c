/*   ch10_6.c                   */
#include <stdio.h>
#include <stdlib.h>
#define  TRUE   1
#define  FALSE  0
#define  SQUARE  n*n
int main()
{
    int n;
    int again = TRUE;

    printf("如果輸入大於 50 程式將自動結束 \n");
    while ( again )   /* 如果小於或等於 50 程式繼續 */ 
    {
       	printf("請輸入數值 ==> ");
       	scanf("%d",&n);      
       	if ( n <= 50 )
	   		printf("平方值是 = %d\n",SQUARE);  
       	else
       	{
       		again = FALSE;  /* 輸入大於 50 則設定 */
       		printf("程式結束\n");
		}    	 
    }
    system("pause");
    return 0;
}



