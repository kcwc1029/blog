/*   ch10_4.c                  */
#include <stdio.h>
#include <stdlib.h>	
#define FMT "x = %d\n"	
void add(int x, int y)
{ 
	printf(FMT,x+y);
	return;
}
void sub(int x, int y)
{
	printf(FMT,x-y);
	return;
}
int main()
{
	add(1,2);
	sub(1,2);
    system("pause");
    return 0;   
}



