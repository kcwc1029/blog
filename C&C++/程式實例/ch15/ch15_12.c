/*   ch15_12.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    while ( ch = getche() )
    {
       if ( isupper(ch) == 0 )
       {
       		printf("\n");
       		break;
	   }
       putchar(ch);
       printf("\n");
    }
    system("pause");
    return 0;
}


