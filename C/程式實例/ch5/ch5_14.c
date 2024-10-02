/*   ch5_14.c                  */
#include <math.h>>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int height, weight;
    float bmi;
    printf("請輸入身高(公分) : ");
    scanf("%d",&height);
    printf("請輸入體重(公斤) : ");
    scanf("%d",&weight);
    bmi = (float) weight / pow(height / 100.0, 2);
    if (bmi >= 28)
        printf("體重肥胖\n");
    else
        printf("體重不肥胖\n");
    system("pause");
    return 0;
}


