/*   ch14_8.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    enum COLOR
    {
    	Red = 1, Green, Blue
	} mycolor;
	printf("請選擇喜歡的顏色 1:Red, 2:Green, 3:Blue = ");
	scanf("%d",&mycolor);
	switch (mycolor)
	{
		case Red:
			printf("你喜歡紅色\n");
			break;
		case Green:
			printf("你喜歡綠色\n");
			break;
		case Blue:
			printf("你喜歡藍色\n");
			break;
		default:
			printf("輸入錯誤\n");
	}
    system("pause");
    return 0;
}



