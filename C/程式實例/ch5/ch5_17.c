/*   ch5_17.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int guess;
    int answer = 5;
start:
    printf("請猜 1-100 間的 1 個數字 : ");
    scanf("%d",&guess);
    if ( guess == answer )    
       goto stop;  /* 跳至 stop 程式結束 */ 
    goto start;
stop:
    printf("恭喜答對了 ! \n");
    system("pause");
    return 0;
}


