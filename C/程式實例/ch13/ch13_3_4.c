/*   ch13_3_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct student
    {
    	char name[12];
    	char ID[10];
    	char gender;
    	int math;
	}; 
	struct student stu = {.name="�x�A��", 
	    				  .gender='M', 
						  .math=90};
	printf("Hi %s �w��A\n", stu.name);
	printf("�ʧO : %c\n", stu.gender);
	printf("�ƾǦ��Z : %d\n", stu.math);
    system("pause");
    return 0;
}


