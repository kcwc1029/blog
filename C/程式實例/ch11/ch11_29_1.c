/*   ch11_29_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[] = "Hung";
    char *ptr = name; 				
    
    puts(ptr);
    printf("執行前的位址 %X\n",ptr);
    ptr = "Jiin-Kwei";   
    puts(ptr);
	printf("執行後的位址 %X\n",ptr);	 	 
    system("pause");
    return 0;
}


