/*   ch7_5.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, sum;
	sum = 0;
    int a[3] = {1, 2, 3, 4};  	/* 宣告元素多於陣列長度 */ 
    
    for ( i = 0; i <= 2; i++ )
		sum += a[i];		
	printf("a[] = %d\n", sum);
	
    system("pause");
    return 0;
}


