/*   ch9_20_2.c                  */
#include <stdio.h>
#include <stdlib.h>
void fun(int n)
{      
    n = 3;          	
    printf("fun 的區域變數 n=%d 的位址 n=%p\n",n,&n);
    return;
}
int main()
{
	int n = 9;
	
	printf("main的區域變數 n=%d 的位址 n=%p\n",n,&n);
	fun(n);
    system("pause");
    return 0;   
}



