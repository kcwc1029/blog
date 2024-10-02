/*   ch5_22.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int month;
    
    printf("請輸入月份 : ");
    scanf("%d", &month);
    switch (month)
    {
    	case 2: printf("%d 月份有 28 天\n", month);
    		break;
    	case 1:
    	case 3:
    	case 5:
    	case 7:
    	case 8:
    	case 10:
    	case 12: printf("%d 月份有 31 天\n", month);
    		break;
    	case 4:
    	case 6:
    	case 9:
    	case 11: printf("%d 月份有 30 天\n", month);
    		break;
    	default:
    		printf("月份輸入錯誤\n");
	}
    system("pause");
    return 0;
}


