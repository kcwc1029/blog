/*   ch2_7.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int s, a, b, c;
    
    a = 5;
    b = 4;
    c = 3;
    s = a * b % c;
    printf("s = a * b %% c = %d\n", s);
     
    system("pause");
    return 0;
}


