/*   ch5_13.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j;

start:
    printf("�п�J 2 �ӼƦr \n==> ");
    scanf("%d%d",&i,&j);
    if ( i > j )   /* �p�G�� 1 �Ʀr�j��� 2 �Ʀr */ 
       goto stop;  /* ���� stop �{������ */ 
    goto start;
stop:
    printf("�{������ \n");
    system("pause");
    return 0;
}


