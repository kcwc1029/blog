/*   ch9_6.c                   */
#include <stdio.h>
#include <stdlib.h>
void larger(int a, int b)  
{
    if ( a < b )
       printf("���j�ȬO %d \n",b);
    else if ( a > b )
       printf("���j�ȬO %d \n",a);
    else
       printf("��ƭȬ۵� \n");
    return;
}
int main()
{
    int i,j;

    printf("�п�J��ƭ� \n ==> ");
    scanf("%d %d",&i,&j);
    larger(i,j);
    system("pause");
    return 0;
}


