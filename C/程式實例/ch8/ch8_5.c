/*   ch8_5.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name[] = "Hung";

    printf("/%s/\n", name);
    printf("/%2s/\n", name);
    printf("/%10s/\n", name);
    printf("/%-10s/\n", name);
    system("pause");
    return 0;
}


