/*   ch11_32_1.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *fruit[] = {"Apple",
				     "Banana",
					 "Grapes"};
    int i;
    char **ptr;
	
	ptr = fruit;
	for ( i = 0; i < 3; i++ )
	{
		printf("�r�ꤺ�e %s\n",*ptr); 	/* ��X�r�ꤺ�e */ 
		printf("�r���} %X\n",ptr++); 	/* ��X�r���} */ 
	}
    system("pause");
    return 0;
}


