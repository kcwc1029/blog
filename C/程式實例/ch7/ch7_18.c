/*   ch7_18.c                   */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double x = 2000000000.0;
    float sec;
    sec = log2(x) / 100;
    printf("�y�ѿ���20���Τ�һݮɶ� --> %6.5f ��\n", sec);
    system("pause");
    return 0;
}


