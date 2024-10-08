/*   ch13_2.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct student
    {
    	char name[12];
    	char phone[10];
    	int math;
	};
	struct student stu;
	printf("請輸入姓名 : ");
	gets(stu.name);
	printf("請輸入手機號碼 : ");
	gets(stu.phone);
	printf("請輸入數學成績 : ");
	scanf("%d", &stu.math);
	printf("Hi %s 歡迎你\n", stu.name);
	printf("手機號碼 : %s\n", stu.phone);
	printf("數學成績 : %d\n", stu.math);
    system("pause");
    return 0;
}


