/*   ch16_6.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int  var,i;
    int  sum = 0;
    float average;

    fp = fopen("out6.txt","w");     /* 開啟檔案 */
    for ( i = 0; i < 5; i++ )
    {
       printf("請輸入資料 %d ==>  ",i+1);
       scanf("%d",&var);
       sum += var;
       fprintf(fp,"%d\n",var); /* 將資料寫入檔案 */ 
    }
    average = (float) sum / 5.0;     /* 求平均   */ 
    fprintf(fp,"平均值是 %6.2f",average);
    fclose(fp);                      /* 關閉檔案 */ 
    system("pause");
    return 0;
}





