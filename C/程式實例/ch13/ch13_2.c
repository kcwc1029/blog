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
	printf("�п�J�m�W : ");
	gets(stu.name);
	printf("�п�J������X : ");
	gets(stu.phone);
	printf("�п�J�ƾǦ��Z : ");
	scanf("%d", &stu.math);
	printf("Hi %s �w��A\n", stu.name);
	printf("������X : %s\n", stu.phone);
	printf("�ƾǦ��Z : %d\n", stu.math);
    system("pause");
    return 0;
}


