/*   ch11_28_5.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n[][3] = {{1,2,3},
				  {4,5,6}};
    int rows, cols; 
	int i, j;				
    
	rows = sizeof(n) / sizeof(n[0]);			 
	cols = sizeof(n[0]) / sizeof(n[0][0]); 		
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			printf("n[%d][%d]=%d\t ¦ì§}=%X\n",i,j, \
			       *(*(n+i)+j), *(n+i)+j); 		 	 
    system("pause");
    return 0;
}


