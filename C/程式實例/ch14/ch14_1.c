/*   ch14_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    union utype
    {
       short i;
       char ch;
    } data;

    printf("�O����Ŷ� short = %d\n",sizeof(short));
    printf("�O����Ŷ� char  = %d\n",sizeof(char));
    printf("�O����Ŷ� data  = %d\n",sizeof(data));
    system("pause");
    return 0;
}


