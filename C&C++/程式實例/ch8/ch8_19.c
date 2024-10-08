/*   ch8_19.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char fruit[3][10];
    int i;
    for ( i = 0; i < 3; i++ )
    {
    	printf("請輸入水果 : ");
    	scanf("%s",fruit[i]);
	}
	printf("你輸入的水果如下 : \n");
	for ( i = 0; i < 3; i++ )
	 	printf("%s\n",fruit[i]); 
    system("pause");
    return 0;
}


