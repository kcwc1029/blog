/*   ch7_11.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int num;
    int flag = 0;			/* 如果 0 代表沒找到 */ 
    int arr[8] = {76, 32, 88, 45, 65, 76, 76, 88};
    
    printf("請輸入陣列的搜尋值 : ");
    scanf("%d", &num);
    for ( i = 0; i < 8; i++ )
		if (arr[i] == num)
		{
			printf("arr[%d] = %d\n", i, num);
			flag = 1;
		}
	if (flag == 0)
		printf("沒有找到\n");
    system("pause");
    return 0;
}


