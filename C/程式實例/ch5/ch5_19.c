/*   ch5_19.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int year, zodiac;
    
	printf("�п�J�褸�X�ͦ~ : ");
	scanf("%d", &year);
	year -= 1900;
	zodiac = year % 12;
	if (zodiac == 0)
        printf("�A���ͨv�O : ��\n");
    else if (zodiac == 1)
        printf("�A���ͨv�O : ��\n");
    else if (zodiac == 2)
        printf("�A���ͨv�O : ��\n");
    else if (zodiac == 3)
        printf("�A���ͨv�O : ��\n");
    else if (zodiac == 4)
        printf("�A���ͨv�O : �s\n");
    else if (zodiac == 5)
        printf("�A���ͨv�O : �D\n");
    else if (zodiac == 6)
        printf("�A���ͨv�O : ��\n");
    else if (zodiac == 7)
        printf("�A���ͨv�O : ��\n");
    else if (zodiac == 8)
        printf("�A���ͨv�O : �U\n");
    else if (zodiac == 9)
        printf("�A���ͨv�O : ��\n");
    else if (zodiac == 10)
        printf("�A���ͨv�O : ��\n");
    else
        printf("�A���ͨv�O : ��\n");
    system("pause");
    return 0;
}


