/*   ch13_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct fruit
    {
    	char name[10];
    	int price;
    	char origin[12];
	} family = {"香蕉", 35, "高雄"};
	struct fruit seven;
	printf("family 超商品項表");
	printf("品名 : %s\n", family.name);
	printf("價格 : %d\n", family.price);
	printf("產地 : %s\n", family.origin);
	seven = family;
	printf("seven  超商品項表");
	printf("品名 : %s\n", seven.name);
	printf("價格 : %d\n", seven.price);
	printf("產地 : %s\n", seven.origin);
    system("pause");
    return 0;
}


