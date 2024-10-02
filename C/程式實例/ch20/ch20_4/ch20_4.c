/*   ch20_4.c                 */
#include <stdio.h>
#include <stdlib.h>
int count = 0;
void counter();
int main()
{
	printf("count = %d\n",count);
	counter();
	printf("count = %d\n",count);
	count++;
	printf("count = %d\n",count);	
}
