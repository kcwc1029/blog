/*   ch11_16.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
    int *ptr;
    
    ptr = &x;
	printf("現在指標位址    = %X\n",ptr);
	ptr++;
	printf("加 1 後指標位址 = %X\n",ptr);
	ptr--;
	printf("減 1 後指標位址 = %X\n",ptr);      
    system("pause");
    return 0;
}


