/*   ch11_24.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {3, 6, 7, 5, 9};
    
    printf("num      = %X\n",num);
	printf("num + 1  = %X\n",num+1);
	printf("&num     = %X\n",&num);
	printf("&num + 1 = %X\n",&num+1);
    system("pause");
    return 0;
}


