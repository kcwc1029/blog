/*   ch7_25.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int data[] = {5, 6, 8, 9};
	int i;
	int n = 4;
	float means, var, dev;
					 
    
    for ( i = 0; i < n; i++ ) 		/* �p�⥭���� */ 
    	means += ((float) data[i] / n);
    var = 0.0;
    for ( i = 0; i < n; i++) 		/* �p���ܲ��ƩM�зǮt */ 
	{
		var += pow(data[i] - means, 2);
		dev += pow(data[i] - means, 2);
	}	
    printf("������ = %4.2f\n", means);
   	var = var / n;
   	printf("�ܲ��� = %4.2f\n", var);
   	dev = pow(dev / 4, 0.5);
   	printf("�зǮt = %4.2f\n", dev);
    system("pause");
    return 0;
}


