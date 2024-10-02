/*   ch6_30.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum,score,fail_count,num;
    int i;         /* 索引 */
    float ave;

    sum = fail_count = 0;
    printf("輸入學生人數 ==> ");
    scanf("%d",&num);

    for ( i = 1; i <= num; i++ )
    {
       printf("輸入成績 : ",i);
       scanf("%d",&score);
       sum += score;
       if ( score < 60 )
	      fail_count++;
    }
    ave = (float) sum / (float) num;
    printf("平均成績是 : %6.2f \n",ave);
    printf("不及格人數 : %d \n",fail_count);
    system("pause");
    return 0;
}


