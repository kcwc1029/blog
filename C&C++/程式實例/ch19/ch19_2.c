/*   ch19_2.c                  */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int binToDecimal(int);
int main()
{
    int x;
    printf("�п�J 2 �i��Ʀr : ");
    scanf("%d", &x);
    printf("2�i��=%d �� 10�i��=%d\n", x, binToDecimal(x));
    system("pause");
    return 0;
}
int binToDecimal(int n)
{
    int number = 0;
	int i = 0; 						/* �w�q�B�z���     */ 
	int rem;
    while (n != 0)
    {
        rem = n % 10;				/* �q�k�쥪�B�z�Ʀr */ 
        n /= 10;
        number += rem*pow(2,i); 	/* �p�� i ��ƪ���  */ 
        i++;
    }
    return number;
}


