/*   ch11_28_3.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n[][3] = {{1,2,3},
				  {4,5,6}};
    int rows, cols; 
	int i, j;
	int *ptr;				
    
    ptr = n[0];			
	rows = sizeof(n) / sizeof(n[0]);			/* �p�� rows �� */ 
	cols = sizeof(n[0]) / sizeof(n[0][0]); 		/* �p�� cols �� */
    for (i = 0; i < rows; i++)
    {
		for (j = 0; j < cols; j++)
			printf("n[i][j]=%X \t n[i][j]=%d\n", ptr, *ptr++); 		 
		printf("\n");
	}	
    system("pause");
    return 0;
}


