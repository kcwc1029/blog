/*   ch13_12.c                   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Books 
{
    char title[20];
	char author[20];		 
    int price;		
};
void show(struct Books *bk);
int main()
{   
    struct Books book;
	
	strcpy(book.title, "C �y�������k��");
	strcpy(book.author, "�x�A��");
	book.price = 620;
	show(&book);	   
    system("pause");
    return 0;
} 
void show(struct Books *bk)
{
	printf("���y�W�� : %s\n", bk->title);
	printf("�@��     : %s\n", bk->author);
	printf("�w��     : %d\n", bk->price);	
}


