/*   ch9_35_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int display(int n[], int len)
{
	printf("%d\n", n[len]);
	if (len <= 0)
		return;
	else
		display(n, len-1);		
}
int main()
{
	int x[] = {3, 4, 2, 5, 7};
	int len;
	len = sizeof(x) / sizeof(x[0]);
	display(x, len-1);
	system("pause");
    return 0;	
}
    


