/*   ch6_19.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int count = 1;
    while ( 1 )
    {
       printf("��J���q�Ʀr : ");
       scanf("%d",&i);
       if ( i == 5 )   /* �]�w���q�Ʀr */ 
	      break;
       count++;
    }
    printf("�� %d ���q�� \n",count);
    system("pause");
    return 0;
}


