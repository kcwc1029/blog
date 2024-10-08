/*   ch19_1.c                  */
#include <stdlib.h>
#include <stdio.h>
int decimalToBin(int);
int main()
{
    int x;
    printf("請輸入 10 進位數字 : ");
    scanf("%d", &x);
    printf("10進位=%d 轉 2進位=%d\n", x, decimalToBin(x));
    system("pause");
    return 0;
}
int decimalToBin(int n)
{
    int binary = 0; 		/* 紀錄 2 進位數字 */
	int times = 1;			/* 每一次增加 10 倍*/ 
    int rem;				/* 餘數            */ 
	int i = 1;  			/* 求餘數迴圈次數  */ 
 
    while (n != 0)
    {
        rem = n % 2;		/* 計算 2 的餘數    */ 
        printf("loop %d: %3d/2, 餘=%d, 商=%d\n",i++,n,rem,n/2);
        n /= 2; 				/* 商           */ 
        binary += rem*times; 	/* 儲存 10 進位 */ 
        times *= 10; 			/* 往左至下一筆  */ 
    }
    return binary;
}
   


