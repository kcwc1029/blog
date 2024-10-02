/*   ch11_24_2.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int num[3];
    int i;

    printf("請輸入 3 個整數\n");
    for (i = 0; i < 3; i++)
    {
    	printf("輸入數字 %d = ", i);
    	scanf("%d", num+i);
	}
    for (i = 0; i < 3; i++)
    {
    	printf("輸出數字 %d = %d\n", i, num[i]);
	}	
    system("pause");
    return 0; 
}


