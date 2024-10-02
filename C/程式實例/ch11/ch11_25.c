/*   ch11_25.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {3, 6, 7, 5, 9};
    int len;
    int i;
    
    len = sizeof(num) / sizeof(num[0]);
	for (i = 0; i < len; i++)
		printf("num[%d)=%d \t*(num+%d)=%d\n",i,num[i],i,*(num+i)); 
    system("pause");
    return 0;
}


