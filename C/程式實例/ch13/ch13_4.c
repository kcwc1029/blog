/*   ch13_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct fruit
    {
    	char name[10];
    	int price;
    	char origin[12];
	} family = {"����", 35, "����"};
	struct fruit seven;
	printf("family �W�ӫ~����");
	printf("�~�W : %s\n", family.name);
	printf("���� : %d\n", family.price);
	printf("���a : %s\n", family.origin);
	seven = family;
	printf("seven  �W�ӫ~����");
	printf("�~�W : %s\n", seven.name);
	printf("���� : %d\n", seven.price);
	printf("���a : %s\n", seven.origin);
    system("pause");
    return 0;
}


