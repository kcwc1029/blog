/*   ch12_1.c                  */
#include <stdio.h>
#include <stdlib.h>
void info(int *);
int main()
{
    int x = 10;
    int *ptr = &x;
    
    printf("x   address = %X\n", &x);
    printf("ptr address = %X\n", ptr);
    printf("呼叫 address\n");
    info(ptr); 			/* 傳遞指標 */
	info(&x);			/* 傳遞位址 */ 
    system("pause");
    return 0;    
}
void info(int *p)
{
	printf("address=%X \t val=%d\n", p, *p);	
}


