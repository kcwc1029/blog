/*   ch7_7.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int score[10],i,sum,num;
    float ave;

    sum = 0;
    printf("�п�J�ǥͤH�� ==> ");
    scanf("%d",&num);
    for ( i = 0; i < num; i++ )
    {
       printf("�п�J���� ==> ");
       scanf("%d",&score[i]);
       sum += score[i];
    }
    ave = (float) sum / (float) num;
    printf("�������ƬO %6.2f \n",ave);
    system("pause");
    return 0; 
}


