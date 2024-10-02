/*   ch4_15.c                               */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float length; 
    double area;
    double pi = 3.1415926;
    
	printf("請輸入五角形邊長 : \n==> ");
	scanf("%f", &length);
	area = (5 * pow(length, 2)) / (4 * tan(pi / 5));
    printf("area --> %5.2f \n", area);
    system("pause");
    return 0;
}


