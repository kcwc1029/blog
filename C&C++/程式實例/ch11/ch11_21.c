/*   ch11_21.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr=NULL; 
    
	gets(ptr);
	printf("@%s@\n",ptr);     
    system("pause");
    return 0;
}


