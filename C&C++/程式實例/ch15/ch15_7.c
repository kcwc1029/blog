/*   ch15_7.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 0; i < 256; i++ )
       if ( isgraph(i) != 0 ) 		/* �O�_�i��ܦr�� */ 
          printf("%4d %c\t",i,i);   /* ���H��� */ 
    system("pause");
    return 0;
}


