/*   ch9_16.c                   */
#include <stdio.h>
#include <stdlib.h>
int factorial(int n)
{
	int fact = 1;
	int i;
	for ( i = 1; i <= n; i++)
	{
		fact *= i;
		printf("%d! = %d\n", i, fact);		
	}	
	return fact;
}
int main()
{
    int n = 5;
    int i;

	printf("factorial(%d) = %d\n",n, factorial(n));	 
    system("pause");
    return 0;
}


