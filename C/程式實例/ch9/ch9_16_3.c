/*   ch9_16_3.c                   */
#include <stdio.h>
#include <stdlib.h>
int sum(int n)
{
	if (n <= 1) 			/* µ²§ô±ø¥ó */ 
		return 1;		
	else
		return n + sum(n-1);			
}
int main()
{
	printf("total = %d\n",sum(5));
	system("pause");
    return 0;	
}
    


