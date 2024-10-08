/*   ch11_23.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {3, 6, 7, 5, 9};
    int len;		/* 陣列長度 */ 
    
    printf("陣列長度 = %d\n",sizeof(num));	
    len = sizeof(num) / sizeof(num[0]);
	printf("陣列元素個數 = %d\n",len);
	printf("陣列的位址   = %X\n",num);
    system("pause");
    return 0;
}


