/*   ch21_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	int n;				/* �w�q�ǥͤH�� */ 
    struct student
    {
    	char name[12];
    	char phone[10];
    	int math;
	};
	struct student *stu;
	printf("�п�J�ǥͤH�� : ");
	scanf("%d",&n);
	stu = (struct student *) malloc(n*sizeof(struct student));
	for (i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("�п�J�m�W : ");
		gets((stu+i)->name);
		printf("�п�J������X : ");
		gets((stu+i)->phone);
		printf("�п�J�ƾǦ��Z : ");
		scanf("%d",&(stu+i)->math);
	}
	for (i = 0; i < n; i++)
	{
		printf("Hi %s �w��A\n", (stu+i)->name);
		printf("������X : %s \t �ƾǦ��Z : %d\n", \
				(stu+i)->phone,(stu+i)->math);
	}
    system("pause");
    return 0;
}


