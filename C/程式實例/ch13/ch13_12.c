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
	
	strcpy(book.title, "C 語言王者歸來");
	strcpy(book.author, "洪錦魁");
	book.price = 620;
	show(&book);	   
    system("pause");
    return 0;
} 
void show(struct Books *bk)
{
	printf("書籍名稱 : %s\n", bk->title);
	printf("作者     : %s\n", bk->author);
	printf("定價     : %d\n", bk->price);	
}


