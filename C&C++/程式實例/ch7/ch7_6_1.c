/*   ch7_6_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    int a[] = {1, 2, 3, 4};  	
    
    size = sizeof(a) / sizeof(a[0]);
    printf("�}�C a �������Ӽ� = %d\n",size);
    system("pause");
    return 0;
}


