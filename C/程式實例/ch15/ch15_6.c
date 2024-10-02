/*   ch15_6.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    while ( ch = getche() )
    {
       if ( isxdigit(ch) == 0 )
          break;
       putchar(ch);
       printf("\n");
    }
    system("pause");
    return 0;
}


