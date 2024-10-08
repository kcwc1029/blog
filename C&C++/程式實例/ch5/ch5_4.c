/*   ch5_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int age;
    printf("請輸入年齡 : ");
    scanf("%d", &age);
    if (age < 20)
    {
    	printf("你年齡太小\n");
    	printf("須年滿20歲才可以購買菸酒\n");
	}
	else
	    printf("歡迎購買菸酒\n");
    system("pause");
    return 0;
}


