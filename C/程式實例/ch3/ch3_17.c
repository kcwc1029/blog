/*   ch3_17.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float a, b;

    printf("請輸入浮點數 : ");
    scanf("%f",&a);
    printf("請輸入科學記號浮點數 : ");
    scanf("%e",&b);
    printf("a = %f\n",a);
    printf("b = %e\n",b);
    printf("a + b = %6.3f\n",a + b);
    system("pause");
    return 0; 
}


