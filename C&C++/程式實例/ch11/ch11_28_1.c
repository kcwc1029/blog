/*   ch11_28_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n[][3] = {{1,2,3},
				  {4,5,6}};
    int rows, cols; 
	int i, j;				
    
	rows = sizeof(n) / sizeof(n[0]);			/* �p�� rows �� */ 
	cols = sizeof(n[0]) / sizeof(n[0][0]); 		/* �p�� cols �� */
	printf("rows=%d \t cols=%d\n", rows, cols);
	printf("n[i][j]�榡���O�����}\n"); 
    for (i = 0; i < rows; i++)
    {
		for (j = 0; j < cols; j++)
			printf("n[i][j]=%X\t",&n[i][j]); 	/* ��X�O�����} */ 
		printf("\n");
	}	
	printf("n[i]+j �榡���O�����}\n"); 
	for (i = 0; i < rows; i++)
    {
		for (j = 0; j < cols; j++)
			printf("n[i]+j=%X\t",n[i]+j); 		/* ��X�O�����} */ 
		printf("\n");
	}	 
    system("pause");
    return 0;
}


