/*   ch3_29.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   float x = 5.3;
   int   y = 9;
   int   z = 4;

   x = y / z;
   printf("���G�O %6.2f\n",x);
   x = (float) y / (float) z;
   printf("���G�O %6.2f\n",x);
   system("pause");
   return 0;
}


