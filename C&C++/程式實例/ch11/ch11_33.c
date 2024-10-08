/*   ch11_33.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int array[5];
   int *ptr, sum, i;

   printf("請輸入 5 個整數 \n : ");
   for ( i = 0; i <= 4; i++ )
      scanf("%d",&array[i]);
   sum = 0;
   for ( ptr = array; ptr <= &array[4]; ptr++ )
      sum += *ptr;
   printf("陣列整數和是 %d\n",sum);
   system("pause");
   return 0;
}


