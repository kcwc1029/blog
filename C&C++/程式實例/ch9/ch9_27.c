/*   ch9_27.c                   */
#include <stdio.h>
#include <stdlib.h>
void swap(int x, int y)
{
    int tmp;
    printf("swap��� x ��} %p\n",&x);
    printf("swap��� y ��} %p\n",&y);
    tmp = x;
    x = y;
    y = tmp;
}
int main()
{
    int x = 5;
    int y = 1;
    printf("main��� x ��} %p\n",&x);
    printf("main��� y ��} %p\n",&y);
    printf("�����իe\n");
    printf("x = %d \t y = %d\n",x,y);
    swap(x, y);
    printf("�����ի�\n");
    printf("x = %d \t y = %d\n",x,y);
    system("pause");
    return 0;
}



