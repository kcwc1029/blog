/*   ch13_8.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
    struct family 
    {
    	char title[12];		/* �ӫ~�W��     */ 
    	int price;			/* ����         */ 
        char supplier[12];  /* ������       */ 
    } items[100] = {{"Coke",25,"�ӥj"},{"�w��",17,"�Τ@"}};
    for (i = 0; i < 2; i++) 
		printf("%s ������O %d, �����ӬO %s\n", \
		       items[i].title, items[i].price, items[i].supplier);   
    system("pause");
    return 0;
} 


