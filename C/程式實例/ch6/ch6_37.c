/*   ch6_37.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int password;
    
    for (i=1; i<=3; i++)
    {
    	printf("請輸入密碼 : ");
    	scanf("%d", &password);
    	if (password == 12345)
    	{
    		printf("密碼正確, 歡迎進入系統\n");
    		break;
    	}
    	else
    		if (i == 3 && password != 12345)
    			printf("密碼錯誤 3 次, 請至櫃台重新申請密碼\n");
	} 		     
    system("pause");
    return 0;
}


