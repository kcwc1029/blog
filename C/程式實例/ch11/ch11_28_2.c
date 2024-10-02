/*   ch11_28_2.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n[][3] = {{1,2,3},
				  {4,5,6}};
    int rows, cols; 
	int i, j;				
    
	rows = sizeof(n) / sizeof(n[0]);			/* 計算 rows 數 */ 
	cols = sizeof(n[0]) / sizeof(n[0][0]); 		/* 計算 cols 數 */
	for (i = 0; i < rows; i++)
    {
		for (j = 0; j < cols; j++)
			printf("n[i][j]=%d\t",*(n[i]+j)); 		 
		printf("\n");
	}	 
    system("pause");
    return 0;
}


