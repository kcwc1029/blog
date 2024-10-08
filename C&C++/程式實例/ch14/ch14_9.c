/*   ch14_9.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	float money;
    enum CARD
    {
    	Platinum = 1, Gold, Silver
	} mycard;
	printf("請輸入卡別 1:Platinum, 2:Gold, 3:Silver = ");
	scanf("%d",&mycard);
	printf("請輸入消費金額 = ");
	scanf("%f",&money);
	switch (mycard)
	{
		case Platinum:
			printf("結帳金額 = %-9.2f\n",money*0.7);
			break;
		case Gold:
			printf("結帳金額 = %-9.2f\n",money*0.8);
			break;
		case Silver:
			printf("結帳金額 = %-9.2f\n",money*0.9);
			break;
		default:
			printf("結帳金額 = %-9.2f\n",money);
	}
    system("pause");
    return 0;
}



