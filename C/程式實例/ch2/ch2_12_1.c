/*   ch2_12_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    float foot = 7.5; 		/* 腳的尺寸 */ 
    
    size = (int) foot + 1;
    printf("你的腳的尺寸是     : %2.1f\n", foot);
    printf("你購買的鞋子尺寸是 : %d\n", size);
    system("pause");
    return 0;
}


