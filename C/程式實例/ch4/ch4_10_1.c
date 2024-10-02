/*   ch4_10_1.c                               */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float x = 3.6;
	float y = 2.4;
	float z; 				
    z = fmod(x, y);
    printf("%5.2f \n", z);
    system("pause");
    return 0;
}


