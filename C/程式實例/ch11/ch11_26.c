/*   ch11_26.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {3, 6, 7, 5, 9};
    int *ptr;
    int i, len;
    int sum = 0;
    
    ptr = num;
    printf("num位址 = %X\n", num);
	printf("ptr位址 = %X\n", ptr);
    len = sizeof(num) / sizeof(num[0]);
	for (i = 0; i < len; i++)
		sum += *ptr++; 		/* 方法 1 加總 */ 
	printf("方法 1 陣列總和 = %d\n",sum);
	printf("num位址 = %X\n", num);
	printf("ptr位址 = %X\n", ptr);
	ptr = num; 
	for (i = 0; i < len; i++)
		sum += *(ptr + i); 	/* 方法 2 加總 */
	printf("方法 2 陣列總和 = %d\n",sum);
	printf("num位址 = %X\n", num);
	printf("ptr位址 = %X\n", ptr);
    system("pause");
    return 0;
}


