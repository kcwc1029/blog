/*   ch11_19.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
    int *ptr;
    char ch = 'K';
    float y = 10.0;
    
    ptr = &x;
	printf("整數   = %d\n",*ptr);
	ptr = &ch;
	printf("字元   = %c\n",*ptr);
	ptr = &y;
	printf("浮點數 = %f\n",ptr);      
    system("pause");
    return 0;
}


