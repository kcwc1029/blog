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
		printf("字串內容 %s\n",*ptr); 	/* 輸出字串內容 */ 
		printf("字串位址 %X\n",ptr++); 	/* 輸出字串位址 */ 
	}
    system("pause");
    return 0;
}


