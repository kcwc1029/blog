/*   ch12_3.c                  */
#include <stdio.h>
#include <stdlib.h>
void square(int *);
int main()
{
    int x = 10;
    
    printf("���� square �e = %d\n", x);
    square(&x); 			
	printf("���� square �� = %d\n", x);
    system("pause");
    return 0;    
}
void square(int *ptr)
{
	*ptr *= *ptr;
	return;	
}


