/*   ch8_9.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[80] = "明志科技大學";

    printf("字串輸出如下 \n");
    puts(str);
    puts(str+4);
    puts(&str[4]);
    system("pause");
    return 0;
}


