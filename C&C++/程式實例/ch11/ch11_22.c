/*   ch11_22.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {3, 6, 7, 5, 9};
    int i;
    
    printf("num¤º®e = %X\n",num);	
	for (i = 0; i < 5; i++)
		printf("num[%d]  = %X\n",i, &num[i]); 
    system("pause");
    return 0;
}


