/*   ch15_11.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 0;
    int ch;

    while ( ( ch = getche() ) != '\r' )
       if ( islower(ch) )  /* �p�G�O�p�g�r�� */ 
          count++;         /* �֭p���� */ 
    printf("\n�p�g�r���Ӽ� = %d\n",count);
    system("pause");
    return 0;
}


