/*    ch8_4_2.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[] = "Hung"; 	/* ¦r¦ê«Å§i */ 
    int  i, len;
    
    len = sizeof(name) - 1;
	for ( i = 0; i < len; i++ )    
		printf("%c", name[i]);
	printf("\n");
    system("pause");
    return 0;
}


