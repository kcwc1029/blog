/*   ch12_8_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int max_sum(int [][5], int);
int main()
{
    int n[][5] = {{5, 8, 4, 10, 2},
				  {11, 18, 17, 16, 19},
				  {26, 23, 29, 27, 20}};
    int rows;
    int total;
    
	rows = sizeof(n) / sizeof(n[0]);
	total = max_sum(n, rows);
    printf("最大值加總  = %d\n", total);
    system("pause");
    return 0;
}
int max_sum(int p[][5], int length)
{
    int i, j, max;
    int sum = 0;
    for (i = 0; i < length; i++)
    {
    	max = *(*(p+i));
    	for (j = 0; j < 5; j++)
    	{
    		if (max < *(*(p+i)+j))
    			max = *(*(p+i)+j);
    	}
    	printf("row%d 最大值 : %d\n", i, max);
    	sum += max;
	}   	
	return sum;
}




