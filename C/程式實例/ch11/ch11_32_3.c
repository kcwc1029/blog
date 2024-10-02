/*   ch11_32_3.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *str[] = {"China",
				   "Japan",
				   "France"};
    int i;

    for (i = 0; i < 3; i++)
    	printf("%X : %s\n", str[i], str[i]);
    str[1] = "Germany";
    for (i = 0; i < 3; i++)
    	printf("%X : %s\n", str[i], str[i]);
    system("pause");
    return 0;   
}
