/*   ch11_16.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
    int *ptr;
    
    ptr = &x;
	printf("�{�b���Ц�}    = %X\n",ptr);
	ptr++;
	printf("�[ 1 ����Ц�} = %X\n",ptr);
	ptr--;
	printf("�� 1 ����Ц�} = %X\n",ptr);      
    system("pause");
    return 0;
}


