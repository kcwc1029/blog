/*   ch9_27.c                   */
#include <stdio.h>
#include <stdlib.h>
void swap(int x, int y)
{
    int tmp;
    printf("swap函數 x 位址 %p\n",&x);
    printf("swap函數 y 位址 %p\n",&y);
    tmp = x;
    x = y;
    y = tmp;
}
int main()
{
    int x = 5;
    int y = 1;
    printf("main函數 x 位址 %p\n",&x);
    printf("main函數 y 位址 %p\n",&y);
    printf("執行對調前\n");
    printf("x = %d \t y = %d\n",x,y);
    swap(x, y);
    printf("執行對調後\n");
    printf("x = %d \t y = %d\n",x,y);
    system("pause");
    return 0;
}



