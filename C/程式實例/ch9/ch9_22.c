/*   ch9_22.c                  */
#include <stdio.h>
#include <stdlib.h>
double PI = 3.1415926; 		/* global variable x */ 
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
	printf("�п�J��b�| = ");
	scanf("%lf", &r);
	printf("�ꭱ�n = %lf\n", area(r));
	printf("��P�� = %lf\n", circumference(r));
    system("pause");
    return 0;   
}



