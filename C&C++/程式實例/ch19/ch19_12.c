/*   ch19_12.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct info
    {
    	unsigned int age:7;
    	unsigned int gender:1;
	};
	struct info john;
	int sex, ages;
	printf("�п�J�~�� : ");
	scanf("%d",&ages);
	john.age = ages;
	printf("�п�J�ʧO : ");
	scanf("%d",&sex);
	john.gender = sex;
	struct info mary;
	if (john.gender == 1)
		printf("John�O�k��, ���~ %d ��\n",john.age);
	else
		printf("John�O�k��, ���~ %d ��\n",john.age);
    system("pause");
    return 0;
}


