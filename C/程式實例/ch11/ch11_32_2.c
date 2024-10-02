/*   ch11_32_2.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *str[][2] = {"China", "Beijing",
				      "Japan", "Tokyo",
				      "France", "Paris"};
    int i;

    for (i = 0; i < 3; i++)
    	printf("%s : %s\n", str[i][0], str[i][1]);
    system("pause");
    return 0;   
}
