/*   ch11_15_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    int *ptr; 				
   
    ptr = &x; 		
    printf("�п�J��� : ");
    scanf("%d", ptr);
	printf("�A����J�O : %d\n", *ptr);	    	 	 
    system("pause");
    return 0;
}


