/*   ch13_8.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
    struct family 
    {
    	char title[12];		/* 商品名稱     */ 
    	int price;			/* 價格         */ 
        char supplier[12];  /* 供應商       */ 
    } items[100] = {{"Coke",25,"太古"},{"泡麵",17,"統一"}};
    for (i = 0; i < 2; i++) 
		printf("%s 的價格是 %d, 供應商是 %s\n", \
		       items[i].title, items[i].price, items[i].supplier);   
    system("pause");
    return 0;
} 


