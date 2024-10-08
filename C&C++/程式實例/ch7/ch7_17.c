/*   ch7_17.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k;
    int mymax = 0;
    int sc[][2][3] = {{{1,2,3},
	                    {4,5,6}},
	                   {{7,8,9},
	                    {10,11,12}},
					  };
    for ( i = 0; i < 2; i++ )
		for ( j = 0; j < 2; j++)
		   	for (k = 0; k < 3; k++)
		   	    if (mymax < sc[i][j][k])
		   	    	mymax = sc[i][j][k];
	printf("³Ì¤j­È¬O %d\n",mymax);
    system("pause");
    return 0;
}


