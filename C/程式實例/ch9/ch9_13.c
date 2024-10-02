/*   ch9_13.c                   */
#include <stdio.h>
#include <stdlib.h>
int add(int, int); 	/* 函數原型宣告 */ 
int mul(int, int);  /* 函數原型宣告 */
int main()
{
    int index;
    int x, y;
    
    printf("請輸入 1 或 2 選擇計算方式\n");
    printf("1 : 加法運算\n");
    printf("2 : 乘法運算\n=> ");
    scanf("%d",&index);
    printf("請輸入兩數值 : ");
    scanf("%d %d",&x,&y);
    if (index == 1)
    	printf("%d + %d = %d\n", x, y, add(x, y));
	else if (index == 2)
		printf("%d * %d = %d\n", x, y, mul(x, y));
	else
		printf("計算方式選擇錯誤\n");
    system("pause");
    return 0;
}
int add(int a, int b)
{
	return a + b; 
}
int mul(int c, int d)
{
	return c * d;
}



