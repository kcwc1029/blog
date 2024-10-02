/*   ch4_13.c                               */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double dist; 
	double x1, y1, x2, y2;
	x1 = 1.0;
	y1 = 8.0;
	x2 = 3.0;
	y2 = 10.0;				
    dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    printf("2 點之間的距離 --> %5.2f \n", dist);
    system("pause");
    return 0;
}


