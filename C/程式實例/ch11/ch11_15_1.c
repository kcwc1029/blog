/*   ch11_15_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    int *ptr; 				
   
    ptr = &x; 		
    printf("請輸入資料 : ");
    scanf("%d", ptr);
	printf("你的輸入是 : %d\n", *ptr);	    	 	 
    system("pause");
    return 0;
}


