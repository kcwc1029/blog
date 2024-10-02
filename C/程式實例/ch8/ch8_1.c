/*    ch8_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[] = {'H','u','n','g'};
    int  i;

    for ( i = 0; i < 4; i++ )    
       printf("%c", name[i]);
    printf("\n");
    system("pause");
    return 0;
}


