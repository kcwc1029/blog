/*   ch11_7.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x;
    int *ptr;
    
    x = 10;
    ptr = &x;  
    printf("���e x=%-10d \t *ptr=%-10d\n", x, *ptr);  	/* �ܼ� x ��   */ 
    printf("��} &x=%-10X \t ptr=%-10X\n", &x, ptr); 	/* �ܼ� x ��} */ 
    printf("��} ptr=%X\n", &ptr);          			/* ptr ��}    */     
    system("pause");
    return 0;
}


