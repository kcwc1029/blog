/*   ch3_31.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int dist, speed;
	int total_hour, days, hours;
	
	dist = 384400; 				/* 地球到月亮的距離          */ 
	speed = 1225; 				/* 1 馬赫速度每小時 1225公里 */
	total_hour = dist / speed;
	days = total_hour / 24;
	hours = total_hour % 24; 
    printf("天數 %d \n", days);
    printf("時數 %d \n", hours);
    system("pause");
    return 0;
}


