/*   ch11_17.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double x = 10.0;
    double *ptr;
    
    ptr = &x;
	printf("�{�b���Ц�}    = %X\n",ptr);
	ptr++;
	printf("�[ 1 ����Ц�} = %X\n",ptr);
	ptr--;
	printf("�� 1 ����Ц�} = %X\n",ptr);      
    system("pause");
    return 0;
}


