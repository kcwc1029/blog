/*   ch4_14.c                               */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float loan, year, rate, monthrate; 
    double molecules, denominator;
    double monthlyPay, totalPay;
    
	printf("�п�J�U�ڪ��B : \n==> ");
	scanf("%f", &loan);
	printf("�п�J�~�� : \n==> ");
	scanf("%f", &year);
	printf("�п�J�~�Q�v : \n==> ");
	scanf("%f", &rate);
	monthrate = rate / (12*100); 	/* �~�Q�v�令��Q�v */
/* �p��C���ٴڪ��B */
    molecules = loan * monthrate;
	denominator = 1 - (1 / pow(1+monthrate, year*12));
	monthlyPay = molecules / denominator;
	totalPay = monthlyPay * year * 12; 
    printf("�C���ٴڪ��B --> %d \n", (int) monthlyPay);
    printf("�`�@�ٴڪ��B --> %d \n", (int) totalPay);
    system("pause");
    return 0;
}


