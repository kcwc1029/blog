/*   ch7_8.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int score[10]; 		/* 假設最多是 10 個學生 */ 
	int i,sum;
    float ave;
    i = 0;
    sum = 0;
    printf("輸入 0 代表輸入結束\n");
    do
    {
       printf("請輸入分數 ==> ");
       scanf("%d",&score[i]);
       sum += score[i];
    } while (score[i++] > 0);
    ave = (float) sum / (i - 1); 
    printf("平均分數是 %6.2f \n",ave);
    system("pause");
    return 0; 
}


