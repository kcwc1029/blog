/*   ch8_8.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[80] = "Ming-Chi Institute of Technology";

    printf("¦r¦ê¿é¥X¦p¤U \n");
    puts(str);
    puts(str+4);
    puts(&str[4]);
    system("pause");
    return 0;
}


