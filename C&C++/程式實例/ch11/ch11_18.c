/*   ch11_18.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
    int *ptr;
    
    ptr = &x;
	printf("�{�b���Ц�}    = %X\n",ptr);
	ptr += 3;
	printf("�[ 3 ����Ц�} = %X\n",ptr);
	ptr -= 3;
	printf("�� 3 ����Ц�} = %X\n",ptr);      
    system("pause");
    return 0;
}


