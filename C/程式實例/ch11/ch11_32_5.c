/*   ch11_32_5.c                 */
#include <stdio.h>
#include <stdlib.h>
#define LEN 3
int main()
{
	char *str[LEN] = {};
	char s[80];			      
    int i;

    for (i = 0; i < LEN; i++)
    	printf("%X : %s\n", str[i], str[i]);
    str[0] = "China";
    str[1] = "Japan";
	str[2] = "France";
    for (i = 0; i < LEN; i++)
    	printf("%X : %s\n", str[i], str[i]);
    system("pause");
    return 0;   
}


