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
	struct student stu = {.name="洪錦魁", 
	    				  .gender='M', 
						  .math=90};
	printf("Hi %s 歡迎你\n", stu.name);
	printf("性別 : %c\n", stu.gender);
	printf("數學成績 : %d\n", stu.math);
    system("pause");
    return 0;
}


