/*   ch7_25.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int data[] = {5, 6, 8, 9};
	int i;
	int n = 4;
	float means, var, dev;
					 
    
    for ( i = 0; i < n; i++ ) 		/* 計算平均值 */ 
    	means += ((float) data[i] / n);
    var = 0.0;
    for ( i = 0; i < n; i++) 		/* 計算變異數和標準差 */ 
	{
		var += pow(data[i] - means, 2);
		dev += pow(data[i] - means, 2);
	}	
    printf("平均值 = %4.2f\n", means);
   	var = var / n;
   	printf("變異數 = %4.2f\n", var);
   	dev = pow(dev / 4, 0.5);
   	printf("標準差 = %4.2f\n", dev);
    system("pause");
    return 0;
}


