/*   ch9_15_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int weather();
void comment_weather(int);
int main()
{
    comment_weather(weather());
    system("pause");
    return 0;
}
int weather()
{
	int temperature;
	printf("請輸入現在溫度 : ");
	scanf("%d",&temperature);
	return temperature;	 
}
void comment_weather(int t)
{
	if (t >= 26)
		printf("現在天氣很熱\n");
	else if (t > 15)
		printf("這是舒適的溫度\n");
	else if (t > 5)
	    printf("天氣有一點冷\n");
	else
		printf("酷寒的天氣\n");
}


