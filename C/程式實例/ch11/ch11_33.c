/*   ch11_33.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int array[5];
   int *ptr, sum, i;

   printf("�п�J 5 �Ӿ�� \n : ");
   for ( i = 0; i <= 4; i++ )
      scanf("%d",&array[i]);
   sum = 0;
   for ( ptr = array; ptr <= &array[4]; ptr++ )
      sum += *ptr;
   printf("�}�C��ƩM�O %d\n",sum);
   system("pause");
   return 0;
}


