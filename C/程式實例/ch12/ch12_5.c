/*   ch12_5.c                  */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
void circle(int, float *, float *);
int main()
{
    int r = 5;
    float area, circumference;
    
	circle(r, &area, &circumference);
    printf("r=%d �ꭱ�n�O %f\n", r, area);
    printf("r=%d ��P���O %f\n", r, circumference);
    system("pause");
    return 0;
}
void circle(int r, float *area, float *circum)
{
    *area = PI * r * r;
    *circum = 2 * PI * r;
}




