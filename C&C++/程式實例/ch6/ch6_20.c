/*   ch6_20.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int counter = 0;

    for ( i = 0; i <= 100; i++ )
    {
       counter++;
       if ( i >= 5 )
	      continue;
       printf("���ެO %d \n",i);
    }
    printf("�j����榸�� %d \n",counter);
    system("pause");
    return 0;
}


