/*   ch19_1.c                  */
#include <stdlib.h>
#include <stdio.h>
int decimalToBin(int);
int main()
{
    int x;
    printf("�п�J 10 �i��Ʀr : ");
    scanf("%d", &x);
    printf("10�i��=%d �� 2�i��=%d\n", x, decimalToBin(x));
    system("pause");
    return 0;
}
int decimalToBin(int n)
{
    int binary = 0; 		/* ���� 2 �i��Ʀr */
	int times = 1;			/* �C�@���W�[ 10 ��*/ 
    int rem;				/* �l��            */ 
	int i = 1;  			/* �D�l�ưj�馸��  */ 
 
    while (n != 0)
    {
        rem = n % 2;		/* �p�� 2 ���l��    */ 
        printf("loop %d: %3d/2, �l=%d, ��=%d\n",i++,n,rem,n/2);
        n /= 2; 				/* ��           */ 
        binary += rem*times; 	/* �x�s 10 �i�� */ 
        times *= 10; 			/* �����ܤU�@��  */ 
    }
    return binary;
}
   


