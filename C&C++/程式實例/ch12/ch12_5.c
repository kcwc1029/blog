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
    printf("r=%d 圓面積是 %f\n", r, area);
    printf("r=%d 圓周長是 %f\n", r, circumference);
    system("pause");
    return 0;
}
void circle(int r, float *area, float *circum)
{
    *area = PI * r * r;
    *circum = 2 * PI * r;
}




