/*   ch10_3.c                  */
#include <stdio.h>
#include <stdlib.h>		
double area(float r)
{ 
	#define PI 3.1415926        	
    return PI * r * r;
}
double circumference(float r)
{
	return 2 * PI * r;
}
int main()
{
	double r;
	printf("�п�J��b�| = ");
	scanf("%lf", &r);
	printf("�魱�n = %lf\n", area(r));
	printf("��P�� = %lf\n", circumference(r));
    system("pause");
    return 0;   
}



