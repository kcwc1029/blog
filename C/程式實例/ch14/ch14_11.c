/*   ch14_11.c                   */
#include <stdio.h>
#include <stdlib.h>
typedef struct Books 
{
    char title[20];
	char author[20];		 
    int price;		
} BOOK;
void show(BOOK);
int main()
{   
    BOOK book={"C �y�������k��","�x�A��",620};
	show(book);	   
    system("pause");
    return 0;
} 
void show(BOOK bk)
{
	printf("���y�W�� : %s\n", bk.title);
	printf("�@��     : %s\n", bk.author);
	printf("�w��     : %d\n", bk.price);	
}


