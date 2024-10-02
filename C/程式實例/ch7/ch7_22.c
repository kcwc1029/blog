/*   ch7_22.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j;
    int tmp;
    int num1[][3] = {{2, 5, 6},
	                 {8, 5, 4},
					 {3, 8, 6}};
	int num2[][3] = {{56,8, 9},
	                 {76,55,2},
					 {6, 2, 4}};
	int num3[3][3]; 
    for ( i = 0; i < 3; i++ )     /* 執行相乘 */ 
       for ( j = 0; j < 3; j++ )
       {
          tmp = 0;
          tmp += num1[i][0] * num2[0][j];
          tmp += num1[i][1] * num2[1][j];
          tmp += num1[i][2] * num2[2][j];
          num3[i][j] = tmp;
       }
    printf("列出相乘結果 \n");
    for ( i = 0; i < 3; i++ )
       printf("%3d %3d %3d\n",num3[i][0],num3[i][1],num3[i][2]);
    system("pause");
    return 0;
}


