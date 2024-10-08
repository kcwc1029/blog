/*   ch9_28.c                   */
#include <stdio.h>
#include <stdlib.h>
void swap(int data[])
{
    int tmp;
    tmp = data[0];
    data[0] = data[1];
    data[1] = tmp;
}
int main()
{
	int num[2];
    int x = 5;
    int y = 1;
    num[0] = x;
    num[1] = y;
    printf("執行對調前\n");
    printf("x = %d \t y = %d\n",x,y);
    swap(num);
    x = num[0];
    y = num[1];
    printf("執行對調後\n");
    printf("x = %d \t y = %d\n",x,y);
    system("pause");
    return 0;
}



