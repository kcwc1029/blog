/*   ch10_8.c                   */
#include <stdio.h>
#include <stdlib.h>
#define  MAX(a,b) ( a > b ) ? a : b
int main()
{
    int x, y;

    printf("�п�J 2 �ӭ� : ");
    scanf("%d %d",&x, &y);
    printf("���j�� = %d\n",MAX(x,y));
    system("pause");
    return 0;
}



