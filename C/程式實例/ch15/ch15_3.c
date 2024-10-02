/*   ch15_3.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 0; i < 130 ; i++ )
    {
       if ( isascii(i) == 0 )
          printf("i = %d ¤£¬O ascii ½X­È\n",i);
    }
    system("pause");
    return 0;
}


