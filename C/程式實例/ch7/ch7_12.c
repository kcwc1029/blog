/*   ch7_12.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j;
    int sc[2][3] = {{90, 80, 95},
	                {95, 90, 85}};
    for ( i = 0; i < 2; i++ )
		for ( j= 0; j < 3; j++)
			printf("�ǥ� %d ���� %d ���Ҹզ��Z�O %d\n",i+1,j+1,sc[i][j]);
    system("pause");
    return 0;
}


