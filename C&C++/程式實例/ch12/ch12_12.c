/*   ch12_12.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i;

    puts("¿é¥X¦p¤U");
    printf("argc = %d\n", argc);
    for ( i = 0; i < argc; i++ )
       puts(argv[i]);
    system("pause");
    return 0;
}


