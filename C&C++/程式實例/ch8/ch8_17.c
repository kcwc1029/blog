/*   ch8_17.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char code[] = "Ming52Chi";
    printf("��l���ҽX = %s\n", code);
    strupr(code);
    printf("�j�g���ҽX = %s\n", code);
    strlwr(code);
	printf("�p�g���ҽX = %s\n", code);
    system("pause");
    return 0;
}


