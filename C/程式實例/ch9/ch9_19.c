/*   ch9_19.c                  */
#include <stdio.h>
#include <stdlib.h>
void fun(int n)
{
    int x = 5;
	                          	
    printf("fun 的區域變數 x = %d\n", x);
    printf("fun 的區域變數 n = %d\n", n);
    return;
}
int main()
{
	int x = 10;
	int n = 9;
	printf("執行前 main 的區域變數 x = %d\n", x);
	printf("執行前 main 的區域變數 n = %d\n", n);
	fun(20);
	printf("執行後 main 的區域變數 x = %d\n", x);
	printf("執行後 main 的區域變數 n = %d\n", n);
    system("pause");
    return 0;   
}



