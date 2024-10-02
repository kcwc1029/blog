/*   ch9_31.c                   */
#include <stdio.h>
#include <stdlib.h>
int len; 							/* 全域變數   */ 
void sort(int []), display(int []); /* 函數原型告 */ 
int main()
{
    int  data[] = {3, 6, 7, 5, 9}; 	/* 欲排序數字 */
    
	len = sizeof(data) / sizeof(data[0]);
    printf("排序前 : ");
    display(data);
    sort(data); 					/* 執行排序   */   
    printf("排序後 : ");
    display(data);
    system("pause");
    return 0;
}
void sort(int num[])
{
	int i, j, flag, tmp;

	for ( i = 1; i < len; i++ )
    {
       flag = 1;
       for ( j = 0; j < (len-1); j++ )
	      if ( num[j] > num[j+1] )
	      {
	          tmp = num[j];
	          num[j] = num[j+1];
	          num[j+1] = tmp;
	          flag = 0;
	      }
       if ( flag )
          break;
    }
}
void display(int arr[])
{
	int i;

	for (i = 0; i < len; i++)
		printf("%d\t",arr[i]);
	printf("\n");
}



