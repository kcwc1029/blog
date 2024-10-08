/*   ch11_28.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[10];
    int *ptr = num; 				
    int i, count;
	int sum = 0;
    	
    printf("請輸入陣列元素個數 : ");
    scanf("%d", &count);    
    for (i = 0; i < count; i++)
    {
    	printf("請輸入陣列元素內容 : ");   	
    	scanf("%d", ptr++);
	}    	
	ptr = num;		/* 將指標移回陣列啟始位置 */ 
	for (i = 0; i < count; i++)
		sum += *ptr++;
	printf("總和 = %d\n", sum);	    	 	 
    system("pause");
    return 0;
}


