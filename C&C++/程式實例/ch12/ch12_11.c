/*   ch12_11.c                 */
#include <stdio.h>
#include <stdlib.h>
int *min(int *, int *);
int main()
{
    int x = 10;
    int y = 5;
    int *minval;
    
    minval = min(&x, &y);
    printf("min = %d\n", *minval);
    system("pause");
    return 0;
}
int *min(int *px, int *py)
{
	if (*px > *py)
		return py;
	else
		return px;
}


