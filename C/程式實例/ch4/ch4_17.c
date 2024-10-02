/*   ch4_17.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 3;
    int b = 5;
    int c = 1;
    float r1, r2;
    r1 = (-b + pow((pow(b,2)-4*a*c),0.5)) / (2 * a);
    r2 = (-b - pow((pow(b,2)-4*a*c),0.5)) / (2 * a);
    printf("r1 = %5.2f,  r2 = %5.2f\n", r1, r2);
    system("pause");
    return 0;
}


