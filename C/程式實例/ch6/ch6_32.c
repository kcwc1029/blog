/*   ch6_32.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,tmp;

    printf("�п�J 2 �ӥ���� \n==> ");
    scanf("%d %d",&i,&j);
    while ( j != 0 )
    {
       tmp = i % j;
       i = j;
       j = tmp;
    }
    printf("�̤j�����ƬO %d \n",i);
    system("pause");
    return 0;
}


