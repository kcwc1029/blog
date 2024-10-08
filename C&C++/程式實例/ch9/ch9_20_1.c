/*   ch9_20_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	
	i = 5;
	printf("外層變數 i=%d 的位址 i=%p\n",i,&i);
	printf("執行for迴圈前 i = %d\n", i);
	{
		int i = 1;
		printf("內層變數 i=%d 的位址 i=%p\n",i,&i);
		for ( ; i <= 3; i++)
			printf("i = %d\n",i);
	}	
	printf("執行for迴圈後 i = %d\n", i);
    system("pause");
    return 0;   
}



