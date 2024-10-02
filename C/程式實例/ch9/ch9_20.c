/*   ch9_20.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	
	i = 5;
	printf("執行for迴圈前 i = %d\n", i);
	{
		int i;
		for (i = 1; i <= 3; i++)
			printf("i = %d\n",i);
	}	
	printf("執行for迴圈後 i = %d\n", i);
    system("pause");
    return 0;   
}



