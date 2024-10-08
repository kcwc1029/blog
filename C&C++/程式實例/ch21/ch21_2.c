/*   ch21_2.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
    int *ptr; 

	ptr = (int *) malloc(2*sizeof(int));   
    *ptr = 10;
    *(ptr+1) = 20;
    for (i = 0; i < 2; i++)
		printf("*(ptr+%d) = %d\n",i,*(ptr+i));      
    system("pause");
    return 0;
}


