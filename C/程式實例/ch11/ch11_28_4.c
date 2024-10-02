/*   ch11_28_4.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
	int *p, **ptr; 
	
    p = &x;			
	ptr = &p;
	printf("x=%d \t\t &x=%X\n", x, &x);
	printf("p=%X \t &p=%X \t *p=%d\n", p, &p, *p);
	printf("ptr=%X \t &ptr=%X \t *ptr=%X \t **ptr=%d\n", \
	       ptr, &ptr, *ptr, **ptr);
    system("pause");
    return 0;
}


