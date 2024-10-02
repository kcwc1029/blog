/*   ch21_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr; 

	ptr = (int *) malloc(sizeof(int));   
    *ptr = 10;
	printf("*ptr = %d\n",*ptr);      
    system("pause");
    return 0;
}


