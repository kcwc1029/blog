/*   ch11_29_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[] = "Hung";
    char *ptr = name; 				
    
    puts(ptr);
    printf("����e����} %X\n",ptr);
    ptr = "Jiin-Kwei";   
    puts(ptr);
	printf("����᪺��} %X\n",ptr);	 	 
    system("pause");
    return 0;
}


