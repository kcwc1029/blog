/*   ch19_2.c                  */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int binToDecimal(int);
int main()
{
    int x;
    printf("請輸入 2 進位數字 : ");
    scanf("%d", &x);
    printf("2進位=%d 轉 10進位=%d\n", x, binToDecimal(x));
    system("pause");
    return 0;
}
int binToDecimal(int n)
{
    int number = 0;
	int i = 0; 						/* 定義處理位數     */ 
	int rem;
    while (n != 0)
    {
        rem = n % 10;				/* 從右到左處理數字 */ 
        n /= 10;
        number += rem*pow(2,i); 	/* 計算 i 位數的值  */ 
        i++;
    }
    return number;
}


