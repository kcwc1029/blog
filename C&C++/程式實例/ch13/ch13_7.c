/*   ch13_7.c                   */
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
    } items[100];
    for (i = 0; i < 2; i++)
    {
		printf("商品名稱 : ");
		gets(items[i].title);
		printf("商品價格 : ");
		scanf("%d",&items[i].price);
		fflush(stdin);
		printf("供應商   : ");
		gets(items[i].supplier); 
	}
    for (i = 0; i < 2; i++) 
		printf("%s 的賈格是 %d, 供應商是 %s\n", \
		       items[i].title, items[i].price, items[i].supplier);   
    system("pause");
    return 0;
} 


