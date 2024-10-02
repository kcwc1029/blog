/*   ch4_11.c                               */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double money; 				
    money = 50000 * pow(1+0.015, 5);
    printf("5 年後本金總和 --> %8.2f \n", money);
    system("pause");
    return 0;
}


