/*   ch11_31.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[15];
    char *ptr1=name;
	
	printf("請輸入帳號 : ");
	gets(name);
	printf("Hi %s 歡迎進入系統\n",ptr1); 	 	 
    system("pause");
    return 0;
}


