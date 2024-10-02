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
		printf("字串內容 %s\n",fruit[i]); 	/* 輸出字串內容 */ 
		printf("字串位址 %X\n",fruit[i]); 	/* 輸出字串位址 */ 
	}
    system("pause");
    return 0;
}


