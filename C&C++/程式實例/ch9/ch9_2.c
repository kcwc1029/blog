/*   ch9_2.c                   */
#include <stdio.h>
#include <stdlib.h>
void output(); 		/* 函數原型宣告 */ 
int main()
{
    output();
    printf("ch9_1.c\n");
    output();
    system("pause");
    return 0;
}
void output()
{
    printf("output!\n");
    return;
}



