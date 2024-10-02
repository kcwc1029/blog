/*   ch13_3_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct student
    {
    	char name[12];
    	char gender;
    	int math;
	} stu = {"洪錦魁", 'M', 90};
	
	printf("Hi %s 歡迎你\n", stu.name);
	printf("性別 : %c\n", stu.gender);
	printf("數學成績 : %d\n", stu.math);
    system("pause");
    return 0;
}


