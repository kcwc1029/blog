/*   ch5_7.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    int ages;

    printf("�A�O�_�n�r�� ?(y/n) ");
    ch = getche();
    printf("\n");
    
    if ( ch == 'y' )
    {
       printf("�A�X�� ? ");
       scanf("%d",&ages);
       if ( ages < 18 )
	      printf("�藍�_�A�~�֤Ӥp \n");
       else
	      printf("�A�ݭn�Ҿr�� \n");
    }
    system("pause");
    return 0;
}


