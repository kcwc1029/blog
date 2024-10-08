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

	printf("請輸入帳號 : ",acc);
	gets(acc); 
	printf("請輸入密碼 : ",pass);
	gets(pass);
	if (strcmp(account, acc) == 0)
	{
		if (strcmp(password, pass) == 0)
			printf("歡迎進入Deepmind系統\n");
		else
			printf("密碼錯誤\n");
	} 
	else
		printf("帳號錯誤\n");
    system("pause");
    return 0;
}






































































































































































































