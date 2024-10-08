/*   ch11_18.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
    int *ptr;
    
    ptr = &x;
	printf("現在指標位址    = %X\n",ptr);
	ptr += 3;
	printf("加 3 後指標位址 = %X\n",ptr);
	ptr -= 3;
	printf("減 3 後指標位址 = %X\n",ptr);      
    system("pause");
    return 0;
}


