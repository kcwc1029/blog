/*   ch5_14.c                  */
#include <math.h>>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int height, weight;
    float bmi;
    printf("�п�J����(����) : ");
    scanf("%d",&height);
    printf("�п�J�魫(����) : ");
    scanf("%d",&weight);
    bmi = (float) weight / pow(height / 100.0, 2);
    if (bmi >= 28)
        printf("�魫�έD\n");
    else
        printf("�魫���έD\n");
    system("pause");
    return 0;
}


