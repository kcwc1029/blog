/*   ch11_31.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[15];
    char *ptr1=name;
	
	printf("�п�J�b�� : ");
	gets(name);
	printf("Hi %s �w��i�J�t��\n",ptr1); 	 	 
    system("pause");
    return 0;
}


