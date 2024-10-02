/*   ch8_18.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char code[] = "deepmind";
    printf("原始字串 = %s\n", code);
    strrev(code);
    printf("反向字串 = %s\n", code);
    system("pause");
    return 0;
}


