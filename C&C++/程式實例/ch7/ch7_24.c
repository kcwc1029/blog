/*   ch7_24.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int magic[3][3];
    int n;              			/* n * n �x�} */
    int i,j,k;

    n = 3;
    for ( i = 0; i < n; i++ )
       for ( j = 0; j < n; j++ )
          magic[i][j] = 0; 			/*���O�x�}���e�� 0*/ 
    i = 1;
    j = ( n / 2 ) - 1;
    for ( k = 1; k <= n*n; k++ )
    {
       i--;
       j++;               			/* �W�h 1 */
       if ( ( i == -1 ) && ( j == n ) )    /* �W�h 6 */
       {
          i = 1;
          j = n - 1;
       }
       else
       {
          if ( i == -1 )  			/* �W�h 2 */
             i = n - 1;
          else
             if ( j == n )  		/* �W�h 3 */
                j = 0;
       }
       if ( magic[i][j] != 0 )   	/* �W�h 4 */
       {
          i += 2;
          j--;
       }
       magic[i][j] = k;
    }
    printf("%d * %d �]�N��� \n",n,n);
    for ( i = 0; i < n; i++ )
    {
       for ( j = 0; j < n; j++ )
          printf("%5d", magic[i][j]);
       printf("\n");
    }
    system("pause");
    return 0;    
}
