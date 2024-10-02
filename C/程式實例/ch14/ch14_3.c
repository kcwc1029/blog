/*   ch14_3.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    union utype
    {
       short i;
       char ch;
    } data;

    data.i = 0x5EC6;
    printf("data.i  = %X\n",data.i);
    data.ch = 'A';
    printf("data.ch = %c\n",data.ch);
    printf("data.i  = %X\n",data.i);
    system("pause");
    return 0;
}



