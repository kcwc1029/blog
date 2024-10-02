/*   ch13_9.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct company 
    {
    	char name[12];		/* 業務姓名     */ 
    	int book;			/* 書籍業績     */ 
        int software;       /* 軟體業績     */ 
    } sales;
    struct company *ptr;
    ptr = &sales;
	printf("業務姓名     : ");
	gets(ptr->name);
	printf("book業績     : ");
	scanf("%d", &ptr->book);
	printf("software業績 : ");
	scanf("%d", &ptr->software);
/* 輸出 */	
	printf("%s 業績說明\n",ptr->name);
	printf("book業績     = %d\n",ptr->book);
	printf("software業績 = %d\n",ptr->software);  
	printf("總業績       = %d\n",ptr->book+ptr->software); 
    system("pause");
    return 0;
} 


