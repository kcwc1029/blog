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
	printf("���   = %d\n",*ptr);
	ptr = &ch;
	printf("�r��   = %c\n",*ptr);
	ptr = &y;
	printf("�B�I�� = %f\n",ptr);      
    system("pause");
    return 0;
}


