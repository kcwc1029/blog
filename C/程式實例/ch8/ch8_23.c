/*   ch8_23.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char account[] = "hung";
    char password[] = "kwei";
    char acc[10];
    char pass[10];

	printf("�п�J�b�� : ",acc);
	gets(acc); 
	printf("�п�J�K�X : ",pass);
	gets(pass);
	if (strcmp(account, acc) == 0)
	{
		if (strcmp(password, pass) == 0)
			printf("�w��i�JDeepmind�t��\n");
		else
			printf("�K�X���~\n");
	} 
	else
		printf("�b�����~\n");
    system("pause");
    return 0;
}






































































































































































































