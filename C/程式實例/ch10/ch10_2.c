/*   ch10_2.c                  */
#include <stdio.h>
#include <stdlib.h>
const double PI=3.1415926; 		
double area(float r)
{        	
    return PI * r * r;
}
double circumference(float r)
{
	return 2 * PI * r;
}
int main()
{
	double r;
	printf("½Ð¿é¤J¶ê¥b®| = ");
	scanf("%lf", &r);
	printf("¶é­±¿n = %lf\n", area(r));
	printf("¶é©Pªø = %lf\n", circumference(r));
    system("pause");
    return 0;   
}



