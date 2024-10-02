#include <math.h>
#define PI 3.14159
double display(double);
double area(double r)
{
	double ar;
	ar = PI * pow(r,2); 
	display(ar);
	return;
}
