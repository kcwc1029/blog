/*   ch7_23.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int magic[4][4] = {{4, 6, 8, 10},
                       {12,14,16,18},
                       {20,22,24,26},
                       {28,30,32,34}};
	int sum;          /* 最小值與最大值之和    */
	int i,j;
 
	sum = magic[0][0] + magic[3][3];
	for ( i = 0, j = 0; i < 4; i++, j++ )
		magic[i][j] = sum - magic[i][j];
	for ( i = 0, j = 3; i < 4; i++, j-- )
		magic[i][j] = sum - magic[i][j];
	printf("最後的魔術方塊如下 : \n");
	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
			printf("%5d",magic[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;        
}


