/*   ch9_16_1.c                   */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int recur(int i)
{
	printf("%d\n",i);
	sleep(1);
	if (i <= 1) 			/* �������� */ 
		return 0;
	else
		return recur(i-1);	/* �C���I�s���ۤv�� 1 */ 
}
int main()
{
	recur(5);
	system("pause");
    return 0;	
}
    


