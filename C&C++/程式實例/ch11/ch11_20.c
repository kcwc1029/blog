/*   ch11_20.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    int* ptr1;
    int * ptr2;
    
    x = 10;
    ptr1 = &x;  
    printf("�ܼ� x ���� = %d\n", x);
    printf("*ptr1 ����  = %d\n", *ptr1); 
	ptr2 = &x;
	printf("*ptr2 ����  = %d\n", *ptr2);   
    system("pause");
    return 0;
}


