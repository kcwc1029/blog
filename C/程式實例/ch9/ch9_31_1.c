/*   ch9_31_1.c                  */
#include <stdio.h>
#include <stdlib.h>
void average(int [][4],int);
int main()
{
    int num[3][4] = {
                     { 88, 79, 91, 0 },
                     { 86, 84, 90, 0 },
                     { 77, 65, 70, 0 } };
    int i, j, rows;

    rows = sizeof(num) / sizeof(num[0]);
    average(num,rows);
    for ( i = 0; i < 3; i++ )   /* 列印新的陣列 */ 
    {
       for ( j = 0; j < 4; j++ )
          printf("%5d",num[i][j]);
       printf("\n");
    }
    system("pause");
    return 0;   
}
void average(int sc[][4],int rows)
{
    int sum,i,j;

    for ( i = 0; i < rows; i++ )
    {
       sum = 0;
       for ( j = 0; j < 4; j++ )
          sum += sc[i][j];
       sc[i][3] = sum /  3;   /* 平均值放入各列最右 */ 
    }
}



