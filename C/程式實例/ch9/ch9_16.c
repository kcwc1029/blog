/*   ch9_16.c                   */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int recur(int i)
{
	printf("%d ",i);
	sleep(1);
	return recur(i-1);
}
int main()
{
	recur(5);
	system("pause");
    return 0;	
}
    


