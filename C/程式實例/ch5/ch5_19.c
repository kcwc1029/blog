/*   ch5_19.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int year, zodiac;
    
	printf("請輸入西元出生年 : ");
	scanf("%d", &year);
	year -= 1900;
	zodiac = year % 12;
	if (zodiac == 0)
        printf("你的生肖是 : 鼠\n");
    else if (zodiac == 1)
        printf("你的生肖是 : 牛\n");
    else if (zodiac == 2)
        printf("你的生肖是 : 虎\n");
    else if (zodiac == 3)
        printf("你的生肖是 : 兔\n");
    else if (zodiac == 4)
        printf("你的生肖是 : 龍\n");
    else if (zodiac == 5)
        printf("你的生肖是 : 蛇\n");
    else if (zodiac == 6)
        printf("你的生肖是 : 馬\n");
    else if (zodiac == 7)
        printf("你的生肖是 : 羊\n");
    else if (zodiac == 8)
        printf("你的生肖是 : 猴\n");
    else if (zodiac == 9)
        printf("你的生肖是 : 雞\n");
    else if (zodiac == 10)
        printf("你的生肖是 : 狗\n");
    else
        printf("你的生肖是 : 豬\n");
    system("pause");
    return 0;
}


