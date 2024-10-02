/*   ch6_13.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;

    while ( ( ch = getche() ) != '\r' )
    {
       putchar(ch);
       printf("\n");
    }
    system("pause");
    return 0;
}


