/*   ch13_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct student
    {
    	char name[12];
    	char gender;
    	int score;
	};
	struct student stu1;
	printf("���� name    �j�p  = %d\n",sizeof(stu1.name));
	printf("���� gender  �j�p  = %d\n",sizeof(stu1.gender));
	printf("���� score   �j�p  = %d\n",sizeof(stu1.score));
	printf("���c student �j�p  = %d\n",sizeof(stu1));
    system("pause");
    return 0;
}


