/*   ch13_9.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct company 
    {
    	char name[12];		/* �~�ȩm�W     */ 
    	int book;			/* ���y�~�Z     */ 
        int software;       /* �n��~�Z     */ 
    } sales;
    struct company *ptr;
    ptr = &sales;
	printf("�~�ȩm�W     : ");
	gets(ptr->name);
	printf("book�~�Z     : ");
	scanf("%d", &ptr->book);
	printf("software�~�Z : ");
	scanf("%d", &ptr->software);
/* ��X */	
	printf("%s �~�Z����\n",ptr->name);
	printf("book�~�Z     = %d\n",ptr->book);
	printf("software�~�Z = %d\n",ptr->software);  
	printf("�`�~�Z       = %d\n",ptr->book+ptr->software); 
    system("pause");
    return 0;
} 


