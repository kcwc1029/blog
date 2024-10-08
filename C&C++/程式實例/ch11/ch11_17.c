/*   ch11_17.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double x = 10.0;
    double *ptr;
    
    ptr = &x;
	printf("現在指標位址    = %X\n",ptr);
	ptr++;
	printf("加 1 後指標位址 = %X\n",ptr);
	ptr--;
	printf("減 1 後指標位址 = %X\n",ptr);      
    system("pause");
    return 0;
}


