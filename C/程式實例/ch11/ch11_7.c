/*   ch11_7.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    int *ptr;
    
    x = 10;
    ptr = &x;  
    printf("內容 x=%-10d \t *ptr=%-10d\n", x, *ptr);  	/* 變數 x 值   */ 
    printf("位址 &x=%-10X \t ptr=%-10X\n", &x, ptr); 	/* 變數 x 位址 */ 
    printf("位址 ptr=%X\n", &ptr);          			/* ptr 位址    */     
    system("pause");
    return 0;
}


