/*   ch11_29.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[] = "Hung";
    char *ptr = name; 				
    
    while ( *ptr != '\0' )
    	printf("%c", *ptr++);
    printf("\n"); 	 	 
    system("pause");
    return 0;
}


