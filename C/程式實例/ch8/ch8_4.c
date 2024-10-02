/*    ch8_4.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[] = "Hung"; 	/* ¦r¦ê«Å§i */ 
    int  i = 0;
   
	while (name[i] != '\0')    
		printf("%c", name[i++]);
	printf("\n");
    system("pause");
    return 0; 
}


