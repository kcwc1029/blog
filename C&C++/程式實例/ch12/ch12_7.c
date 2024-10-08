/*   ch12_7.c                  */
#include <stdio.h>
#include <stdlib.h>
int getmax(int [], int);
int main()
{
    int n[] = {5, 8, 4, 10, 2};
    int len;
    int max;
    
	len = sizeof(n) / sizeof(n[0]);
	max = getmax(n, len);
    printf("max = %d\n", max);
    system("pause");
    return 0;
}
int getmax(int p[], int length)
{
    int i, max;
    max = *p;
    for (i = 0; i < length; i++)
    	if (max < *(p+i))
			max = *(p+i);
	return max;
}




