/*   ch4_14.c                               */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float loan, year, rate, monthrate; 
    double molecules, denominator;
    double monthlyPay, totalPay;
    
	printf("請輸入貸款金額 : \n==> ");
	scanf("%f", &loan);
	printf("請輸入年限 : \n==> ");
	scanf("%f", &year);
	printf("請輸入年利率 : \n==> ");
	scanf("%f", &rate);
	monthrate = rate / (12*100); 	/* 年利率改成月利率 */
/* 計算每月還款金額 */
    molecules = loan * monthrate;
	denominator = 1 - (1 / pow(1+monthrate, year*12));
	monthlyPay = molecules / denominator;
	totalPay = monthlyPay * year * 12; 
    printf("每月還款金額 --> %d \n", (int) monthlyPay);
    printf("總共還款金額 --> %d \n", (int) totalPay);
    system("pause");
    return 0;
}


