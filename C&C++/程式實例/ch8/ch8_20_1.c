/*   ch8_20_1.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>>
int main()
{
    char fruit[3][10] = {"Apple",
						"Banana",
						"Grapes"};
    int i; 
	for ( i = 0; i < 3; i++ )
	{
		printf("�r�ꤺ�e %s\n",fruit[i]); 	/* ��X�r�ꤺ�e */ 
		printf("�r���} %X\n",fruit[i]); 	/* ��X�r���} */ 
	}
    system("pause");
    return 0;
}


