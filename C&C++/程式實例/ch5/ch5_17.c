/*   ch5_17.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int guess;
    int answer = 5;
start:
    printf("�вq 1-100 ���� 1 �ӼƦr : ");
    scanf("%d",&guess);
    if ( guess == answer )    
       goto stop;  /* ���� stop �{������ */ 
    goto start;
stop:
    printf("���ߵ���F ! \n");
    system("pause");
    return 0;
}


