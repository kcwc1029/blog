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
	printf("成員 name    大小  = %d\n",sizeof(stu1.name));
	printf("成員 gender  大小  = %d\n",sizeof(stu1.gender));
	printf("成員 score   大小  = %d\n",sizeof(stu1.score));
	printf("結構 student 大小  = %d\n",sizeof(stu1));
    system("pause");
    return 0;
}


