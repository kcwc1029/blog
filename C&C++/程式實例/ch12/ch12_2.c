/*   ch12_2.c                  */
#include <stdio.h>
#include <stdlib.h>
int add(int *, int *);
int main()
{
    int x = 10;
    int y = 5;
    int sum;
    
    sum = add(&x, &y); 			
	printf("sum = x + y = %d\n", sum);
    system("pause");
    return 0;    
}
int add(int *p1, int *p2)
{
	return *p1 + *p2;	
}


