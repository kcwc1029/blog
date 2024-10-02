/*   ch6_12.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;

    ch = getche();
    while ( ch != '\r' )
    {
       putchar(ch);
       printf("\n");
       ch = getche();
    }
    system("pause");
    return 0;
}


