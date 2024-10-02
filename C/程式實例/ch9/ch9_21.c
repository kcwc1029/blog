/*   ch9_21.c                  */
#include <stdio.h>
#include <stdlib.h>
int x = 10; 		/* global variable x */ 
void fun(void)
{         	
    printf("fun()  x=%d\taddress=%p\n", x,&x);
    x = 30;
    return;
}
int main()
{
	printf("main() x=%d\taddress=%p\n", x,&x);
	x = 20;
	printf("main() x=%d\taddress=%p\n", x,&x);
	fun();
	printf("main() x=%d\taddress=%p\n", x,&x);
    system("pause");
    return 0;   
}



