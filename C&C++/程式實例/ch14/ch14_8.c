/*   ch14_8.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    enum COLOR
    {
    	Red = 1, Green, Blue
	} mycolor;
	printf("�п�ܳ��w���C�� 1:Red, 2:Green, 3:Blue = ");
	scanf("%d",&mycolor);
	switch (mycolor)
	{
		case Red:
			printf("�A���w����\n");
			break;
		case Green:
			printf("�A���w���\n");
			break;
		case Blue:
			printf("�A���w�Ŧ�\n");
			break;
		default:
			printf("��J���~\n");
	}
    system("pause");
    return 0;
}



