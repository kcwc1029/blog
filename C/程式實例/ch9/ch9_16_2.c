/*   ch9_16_2.c                   */
#include <stdio.h>
#include <stdlib.h>
int recur(int i)
{
	if (i < 1) 			/* �������� */ 
		return 0;		
	else
		recur(i-1);		/* �C���I�s���ۤv�� 1 */ 
	printf("%d\n",i);	
}
int main()
{
	recur(5);
	system("pause");
    return 0;	
}
    


