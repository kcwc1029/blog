/*   ch11_10.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i, k;
   int *ptr;
   
   printf("&i=%X \t &k=%X \t &ptr=%X\n",&i,&k,&ptr); 
   i = 5;
   printf("執行前 i=%d\n",i);
   ptr = &i;
   printf("*ptr=%d\t ptr=%X\t &ptr=%X\n", *ptr, ptr, &ptr);
   k = 10;
   *ptr = k; 			/* 這是更改指標所指位址的內容 */ 
   printf("*ptr=%d\t ptr=%X\t &ptr=%X\n", *ptr, ptr, &ptr);
   printf("執行後 i=%d\n",i);
   system("pause");
   return 0;
}


