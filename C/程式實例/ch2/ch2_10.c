/*   ch2_10.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int a, b;
    float s;
    
    a = 3;
    b = 2;
    s = a / b;
    printf("s = a / b = %3.2f\n", s);
    a = 3;
    b = 2;
    s = (float) a / (float) b;
    printf("s = (float) a / (float) b = %3.2f\n", s);
    system("pause");
    return 0;
}


