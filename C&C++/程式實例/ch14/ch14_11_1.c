/*   ch14_11_1.c                   */
#include <stdio.h>
#include <stdlib.h>
struct Books 
{
    char title[20];
	char author[20];		 
    int price;		
};
typedef struct Books BOOK;
void show(BOOK);
int main()
{   
    BOOK book={"C 語言王者歸來","洪錦魁",620};
	show(book);	   
    system("pause");
    return 0;
} 
void show(BOOK bk)
{
	printf("書籍名稱 : %s\n", bk.title);
	printf("作者     : %s\n", bk.author);
	printf("定價     : %d\n", bk.price);	
}


