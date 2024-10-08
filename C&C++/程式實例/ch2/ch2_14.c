/*   ch2_14.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int a, c, d;
    
    a = 3;
    c = 2;
    a *= c;
    printf("a *= c = %d\n", a);
    a = 3;
    c = 2;
    d = 4;
    a *= c + d;
    printf("a *= c + d = %d\n", a);
    system("pause");
    return 0;
}


