/*   ch6_30.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum,score,fail_count,num;
    int i;         /* ���� */
    float ave;

    sum = fail_count = 0;
    printf("��J�ǥͤH�� ==> ");
    scanf("%d",&num);

    for ( i = 1; i <= num; i++ )
    {
       printf("��J���Z : ",i);
       scanf("%d",&score);
       sum += score;
       if ( score < 60 )
	      fail_count++;
    }
    ave = (float) sum / (float) num;
    printf("�������Z�O : %6.2f \n",ave);
    printf("���ή�H�� : %d \n",fail_count);
    system("pause");
    return 0;
}


