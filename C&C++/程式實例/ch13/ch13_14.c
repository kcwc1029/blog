/*   ch13_14.c                   */
#include <stdio.h>
#include <stdlib.h>
struct data 
{
    char name[20];		 
    int score;		
};
int max(struct data sc[]);
int main()
{  
    int index; 
    
    struct data stu[5] = {{"洪錦魁", 90},
    					  {"洪冰儒", 95},
    					  {"洪雨星", 88},
    					  {"洪冰雨", 85},
    					  {"洪星宇", 92}};
	index = max(stu);
	printf("最高分姓名 : %s\n", stu[index].name);
	printf("最高  分數 : %d\n", stu[index].score);  
    system("pause");
    return 0;
} 
int max(struct data sc[])
{
	int i, index;
	int tmpmax = sc->score;
	for (i = 1; i < 5; i++)
		if (tmpmax < (sc+i)->score)
		{
			tmpmax = (sc+i)->score;
			index = i;
		}
	return index;
}


