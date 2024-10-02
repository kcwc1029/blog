/*   ch19_2.c                  */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int binToDecimal(int);
int main()
{
    int x;
    printf("叫块 2 秈计 : ");
    scanf("%d", &x);
    printf("2秈=%d 锣 10秈=%d\n", x, binToDecimal(x));
    system("pause");
    return 0;
}
int binToDecimal(int n)
{
    int number = 0;
	int i = 0; 						/* ﹚竡矪瞶计     */ 
	int rem;
    while (n != 0)
    {
        rem = n % 10;				/* 眖オ矪瞶计 */ 
        n /= 10;
        number += rem*pow(2,i); 	/* 璸衡 i 计  */ 
        i++;
    }
    return number;
}


