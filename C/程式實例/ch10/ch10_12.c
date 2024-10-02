/*   ch10_12.c                  */
#include <stdio.h>
#include <stdlib.h>
#include "math.h"	
double area(float r)
{         	
    return M_PI * r * r;
}
double circumference(float r)
{
	return 2 * M_PI * r;
}
int main()
{
	double r;
	printf("½Ð¿é¤J¶ê¥b®| = ");
	scanf("%lf", &r);
	printf("¶é­±¿n = %15.10lf\n", area(r));
	printf("¶é©Pªø = %15.10lf\n", circumference(r));
    system("pause");
    return 0;   
}



