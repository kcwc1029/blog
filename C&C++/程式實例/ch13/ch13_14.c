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
    
    struct data stu[5] = {{"�x�A��", 90},
    					  {"�x�B��", 95},
    					  {"�x�B�P", 88},
    					  {"�x�B�B", 85},
    					  {"�x�P�t", 92}};
	index = max(stu);
	printf("�̰����m�W : %s\n", stu[index].name);
	printf("�̰�  ���� : %d\n", stu[index].score);  
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


