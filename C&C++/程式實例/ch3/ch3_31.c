/*   ch3_31.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int dist, speed;
	int total_hour, days, hours;
	
	dist = 384400; 				/* �a�y���G���Z��          */ 
	speed = 1225; 				/* 1 �����t�רC�p�� 1225���� */
	total_hour = dist / speed;
	days = total_hour / 24;
	hours = total_hour % 24; 
    printf("�Ѽ� %d \n", days);
    printf("�ɼ� %d \n", hours);
    system("pause");
    return 0;
}


