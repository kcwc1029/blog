/*   ch4_18.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 2;
    int b = 3;
    int c = 1;
    int d = -2;
    int e = 13;
    int f = -4;
    float x, y;
    x = (e*d - b*f) / (a*d - b*c);
    y = (a*f - e*c) / (a*d - b*c);
    printf("x = %5.2f,  y = %5.2f\n", x, y);
    system("pause");
    return 0;
}


