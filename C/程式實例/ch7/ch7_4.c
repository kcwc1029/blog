/*   ch7_4.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, sum1, sum2, sum3;
	sum1 = sum2 = sum3 = 0;
    int a[3] = {1, 2, 3};
    int b[] = {1, 2, 3}; 			/* 省略宣告陣列長度  */ 
    int c[3] = {5};                 /* 省略宣告元素      */ 
    
    for ( i = 0; i <= 2; i++ )
	{
		sum1 += a[i];
		sum2 += b[i];
		sum3 += c[i];
    }
	printf("a[] = %d\n", sum1);
	printf("b[] = %d\n", sum2);
	printf("c[] = %d\n", sum3);	
	printf("c[0] = %d, c[1] = %d, c[2] = %d\n",c[0],c[1],c[2]);
    system("pause");
    return 0;
}


