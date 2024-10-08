/*   ch12_13.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char code[] = "Ming52Chi";
    char *ptr = code;
    
    printf("原始驗證碼 = %s\n", ptr);
    strupr(ptr);
    printf("大寫驗證碼 = %s\n", ptr);
    strlwr(ptr);
	printf("小寫驗證碼 = %s\n", ptr);
    system("pause");
    return 0;
}


