/*   ch9_20.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	
	i = 5;
	printf("����for�j��e i = %d\n", i);
	{
		int i;
		for (i = 1; i <= 3; i++)
			printf("i = %d\n",i);
	}	
	printf("����for�j��� i = %d\n", i);
    system("pause");
    return 0;   
}



