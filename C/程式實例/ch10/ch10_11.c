/*   ch10_11.c                   */
#include <stdio.h>
#include <stdlib.h>
#define exchange(a,b) {       \
                        int t;\
                        t = a;\
                        a = b;\
                        b = t;\
                      }
int main()
{
   int x = 10;
   int y = 20;

   printf("�����իe\n");
   printf("x = %d \t y = %d\n",x,y);
   exchange(x,y);
   printf("�����ի�\n");
   printf("x = %d \t y = %d\n",x,y);
   system("pause");
   return 0;
}


