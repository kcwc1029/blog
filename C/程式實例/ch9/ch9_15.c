/*   ch9_15.c                   */
#include <stdio.h>
#include <stdlib.h>
float mypow(int, int);
double PI(int);
float mypow(int base, int n)
{
	float val = 1.0;
	int i;
	for ( i = 1; i <= n; i++)
		val *= base;
	return val;
}
double PI(int n)
{
	double pi;
	int i;
	for ( i = 1; i <= n; i++ )
		pi += 4*( mypow(-1,(i+1)) / (2*i-1));	
	return pi;	
}	
int main()
{
    int loop = 100000;
    int i;

    for ( i = 1; i <=  loop; i++)
		if (i % 10000 == 0)
			printf("·í i = %6d®É, PI = %20.19lf\n",i, PI(i));  
    system("pause");
    return 0;
}


