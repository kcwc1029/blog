/*   ch7_9.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int Size = 5;
    int score[Size]; 		/* 假設最多是 5 個學生 */ 
	int i,sum;
    float ave;
    i = 0;
    sum = 0;
    printf("輸入 0 代表輸入結束\n");
    do
    {
       if (i >= Size)
       {
          printf("陣列已滿\n");
          i += 1; 			/* 25列會減 1 */ 
          break;
	   }
       printf("請輸入分數 ==> ");
       scanf("%d",&score[i]);
       sum += score[i];
    } while (score[i++] > 0);
    ave = (float) sum / (i - 1); 
    printf("平均分數是 %6.2f \n",ave);
    system("pause");
    return 0; 
}


