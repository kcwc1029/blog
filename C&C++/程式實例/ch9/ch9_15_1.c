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
	printf("�п�J�{�b�ū� : ");
	scanf("%d",&temperature);
	return temperature;	 
}
void comment_weather(int t)
{
	if (t >= 26)
		printf("�{�b�Ѯ�ܼ�\n");
	else if (t > 15)
		printf("�o�O�ξA���ū�\n");
	else if (t > 5)
	    printf("�Ѯ𦳤@�I�N\n");
	else
		printf("�ŴH���Ѯ�\n");
}


