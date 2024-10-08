/*   ch9_16_2.c                   */
#include <stdio.h>
#include <stdlib.h>
int recur(int i)
{
	if (i < 1) 			/* 結束條件 */ 
		return 0;		
	else
		recur(i-1);		/* 每次呼叫讓自己減 1 */ 
	printf("%d\n",i);	
}
int main()
{
	recur(5);
	system("pause");
    return 0;	
}
    


