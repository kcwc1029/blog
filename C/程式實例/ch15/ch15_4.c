/*   ch15_4.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;

    do
    {
       ch = getche();
       if ( isalpha(ch) )  /* ¿é¤J¬O£¸¯ë¦r¤¸ */ 
       {
          putchar(ch);     /* ¦C¦L */ 
          printf("\n");
       }
    }  while ( iscntrl(ch) );
    system("pause");
    return 0;
}



