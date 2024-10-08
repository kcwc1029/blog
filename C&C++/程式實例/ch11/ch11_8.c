/*   ch11_8.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 6;
    int *ptrint = &x; 
    char ch = 'K';
    char *ptrchar = &ch;
    
    printf("整數指標長度 %d\n", sizeof(ptrint));  	 
    printf("字元指標長度 %d\n", sizeof(ptrchar));       
    system("pause");
    return 0;
}


