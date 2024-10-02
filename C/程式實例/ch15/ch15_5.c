/*   ch15_5.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    ch = getche();
    if ( isdigit(ch) )
    {
       putchar(ch);     /* ¦C¦L¼Æ¦r */ 
       printf("\n");
    }
    else
    	printf("\n");
    system("pause");
    return 0;
}


