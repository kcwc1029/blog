/*   ch4_10.c                  */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double x = 30; 				/* ¨¤«×   */
    double radian;              /* ©·«×   */ 
	double pi = 3.1415926;
	
	radian = x * 2 * pi / 360;
    printf("sin(x) --> %5.2f \n", sin(radian));
    printf("cos(x) --> %5.2f \n", cos(radian));
    printf("tan(x) --> %5.2f \n", tan(radian));
    system("pause");
    return 0;
}


