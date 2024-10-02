/*   ch8_10.c                 */
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[80] = "明志科技大學";
    char str2[80] = "是台灣頂尖科技大學";

    printf("輸出字串如下 \n");
    strcat(str1,str2);
    puts(str1);
    system("pause");
    return 0;
}


