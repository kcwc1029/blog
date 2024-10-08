/*   ch14_2.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    union utype
    {
       short i;
       char ch;
    } data;

    printf("記憶體空間 short = %d\n",sizeof(data.i));
    printf("記憶體空間 char  = %d\n",sizeof(data.ch));
    printf("記憶體空間 data  = %d\n",sizeof(data));
    system("pause");
    return 0;
}


