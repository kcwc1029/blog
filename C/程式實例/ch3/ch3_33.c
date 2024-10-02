/*   ch3_33.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int starting;
	int ending;
	int sum;
	int d;
	
	starting = 1;
	ending = 100;
	d = 1;          /* 等差數列間距 */ 
	sum = (int) ((starting + ending) * (ending - starting + d) / (2 * d));
    printf("1 到 100 的總和是 %4d\n", sum);
    system("pause");
    return 0;
}


