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
	printf("�п�J�d�O 1:Platinum, 2:Gold, 3:Silver = ");
	scanf("%d",&mycard);
	printf("�п�J���O���B = ");
	scanf("%f",&money);
	switch (mycard)
	{
		case Platinum:
			printf("���b���B = %-9.2f\n",money*0.7);
			break;
		case Gold:
			printf("���b���B = %-9.2f\n",money*0.8);
			break;
		case Silver:
			printf("���b���B = %-9.2f\n",money*0.9);
			break;
		default:
			printf("���b���B = %-9.2f\n",money);
	}
    system("pause");
    return 0;
}



