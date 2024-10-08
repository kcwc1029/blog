/*   ch15_7.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    for ( i = 0; i < 256; i++ )
       if ( isgraph(i) != 0 ) 		/* 是否可顯示字元 */ 
          printf("%4d %c\t",i,i);   /* 予以顯示 */ 
    system("pause");
    return 0;
}


