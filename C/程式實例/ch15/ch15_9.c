/*   ch15_9.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int ch;

    for ( ;  ; )    
    {
       ch = getche();
       if ( ispunct(ch) )
       { 
          putchar(ch);
          printf("\n");
       }   
       else
          break;    /* ¸õ¥X for °j°é */ 
    }
    system("pause");
    return 0;
} 


