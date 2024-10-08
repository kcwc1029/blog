/*   ch3_5.c                   */ 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;

    i = 356;
    printf("/%d/\n",i);
    printf("/%2d/\n",i);
    printf("/%5d/\n",i);
    printf("/%-5d/\n",i);
    printf("/%+5d/\n",i);
    printf("/%05d/\n",i);
    system("pause");
    return 0;
}


