/*   ch7_18.c                   */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double x = 2000000000.0;
    float sec;
    sec = log2(x) / 100;
    printf("臉書辨識20億用戶所需時間 --> %6.5f 秒\n", sec);
    system("pause");
    return 0;
}


