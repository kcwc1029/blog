/*   ch11_10.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i, k;
   int *ptr;
   
   printf("&i=%X \t &k=%X \t &ptr=%X\n",&i,&k,&ptr); 
   i = 5;
   printf("����e i=%d\n",i);
   ptr = &i;
   printf("*ptr=%d\t ptr=%X\t &ptr=%X\n", *ptr, ptr, &ptr);
   k = 10;
   *ptr = k; 			/* �o�O�����Щҫ���}�����e */ 
   printf("*ptr=%d\t ptr=%X\t &ptr=%X\n", *ptr, ptr, &ptr);
   printf("����� i=%d\n",i);
   system("pause");
   return 0;
}


