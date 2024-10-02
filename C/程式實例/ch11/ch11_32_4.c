/*   ch11_32_4.c                 */
#include <stdio.h>
#include <stdlib.h>
#define LEN 5
int main()
{
	char *str[LEN] = {};			      
    int i;

    for (i = 0; i < LEN; i++)
    	printf("%X : %s\n", str[i], str[i]);
    system("pause");
    return 0;   
}


