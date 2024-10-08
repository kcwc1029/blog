/*   ch13_13.c                   */
#include <stdio.h>
#include <stdlib.h>
struct data 
{
    char name[20];		 
    int score;		
};
void show(struct data s[]);
int main()
{  
    int top; 
    int index;
    struct data stu[5] = {{"¬xÀA»í", 90},
    					  {"¬x¦B¾§", 95},
    					  {"¬x«B¬P", 88},
    					  {"¬x¦B«B", 85},
    					  {"¬x¬P¦t", 92}};
	show(stu);
    system("pause");
    return 0;
} 
void show(struct data s[])
{
	int i;
	for (i = 0; i < 5; i++)
		printf("%s %d\n",(s+i)->name, (s+i)->score);
}


