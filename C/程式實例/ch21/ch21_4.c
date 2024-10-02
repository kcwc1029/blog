/*   ch21_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	int n;				/* 定義學生人數 */ 
    struct student
    {
    	char name[12];
    	char phone[10];
    	int math;
	};
	struct student *stu;
	printf("請輸入學生人數 : ");
	scanf("%d",&n);
	stu = (struct student *) malloc(n*sizeof(struct student));
	for (i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("請輸入姓名 : ");
		gets((stu+i)->name);
		printf("請輸入手機號碼 : ");
		gets((stu+i)->phone);
		printf("請輸入數學成績 : ");
		scanf("%d",&(stu+i)->math);
	}
	for (i = 0; i < n; i++)
	{
		printf("Hi %s 歡迎你\n", (stu+i)->name);
		printf("手機號碼 : %s \t 數學成績 : %d\n", \
				(stu+i)->phone,(stu+i)->math);
	}
    system("pause");
    return 0;
}


