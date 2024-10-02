/*   ch12_3.c                  */
#include <stdio.h>
#include <stdlib.h>
void square(int *);
int main()
{
    int x = 10;
    
    printf("執行 square 前 = %d\n", x);
    square(&x); 			
	printf("執行 square 後 = %d\n", x);
    system("pause");
    return 0;    
}
void square(int *ptr)
{
	*ptr *= *ptr;
	return;	
}


