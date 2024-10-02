/*   ch2_13.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int i, s;
    
    i = 5;
    s = ++i + 3;
    printf("s = ++i + 3 = %d\n", s);
    i = 5;
    s = 3 + i++;
    printf("s = 3 + i++ = %d\n", s);
    system("pause");
    return 0;
}


