/*   ch9_19.c                  */
#include <stdio.h>
#include <stdlib.h>
void fun(int n)
{
    int x = 5;
	                          	
    printf("fun ���ϰ��ܼ� x = %d\n", x);
    printf("fun ���ϰ��ܼ� n = %d\n", n);
    return;
}
int main()
{
	int x = 10;
	int n = 9;
	printf("����e main ���ϰ��ܼ� x = %d\n", x);
	printf("����e main ���ϰ��ܼ� n = %d\n", n);
	fun(20);
	printf("����� main ���ϰ��ܼ� x = %d\n", x);
	printf("����� main ���ϰ��ܼ� n = %d\n", n);
    system("pause");
    return 0;   
}



