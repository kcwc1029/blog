/*   ch11_9.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int val, i;
   int *ptr;

   i = 20;
   ptr = &i;
   val = *ptr;
   printf("*ptr=%d\t val=%d\n", *ptr, val);
   printf("&i=%X\t &val=%X\t &ptr=%X\n",&i, &val, &ptr);
   system("pause");
   return 0;
}



