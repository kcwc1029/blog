/*   ch9_5.c                   */
#include <stdio.h>
#include <stdlib.h>
void larger(a, b)  /* �ª��ŧi */ 
int a, b;
{
    if ( a < b )
       printf("���j�ȬO %d \n",b);
    else if ( a > b )
       printf("���j�ȬO %d \n",a);
    else
       printf("��ƭȬ۵� \n");
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


