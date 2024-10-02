/*   ch12_15.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[80] = "Introduction to C";
    char *str2 = "This is a good book for C";
    char *s;

    puts("©I¥s strcpy «e");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    s = strcpy(str1,str2);
    puts("©I¥s strcpy «á");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    printf("s    = %s\n",s);
    system("pause");
    return 0;
}



