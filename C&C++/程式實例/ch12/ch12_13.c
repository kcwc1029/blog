/*   ch12_13.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char code[] = "Ming52Chi";
    char *ptr = code;
    
    printf("��l���ҽX = %s\n", ptr);
    strupr(ptr);
    printf("�j�g���ҽX = %s\n", ptr);
    strlwr(ptr);
	printf("�p�g���ҽX = %s\n", ptr);
    system("pause");
    return 0;
}


