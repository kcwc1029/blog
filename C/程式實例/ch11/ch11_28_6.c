/*   ch11_28_6.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n[][3] = {{1,2,3},
				  {4,5,6}};
    
    printf("*n  = %X\n", *n);
    printf("**n = %X\n", **n);	 	 
    system("pause");
    return 0;
}


