/*   ch11_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    float b;
    char c;
    printf(" a �� address = %p\n", &a);
    printf("sizeof(a) = %d\n",sizeof(a));
    printf(" b �� address = %p\n", &b);
    printf("sizeof(b) = %d\n",sizeof(b));
    printf(" c �� address = %p\n", &c);
    printf("sizeof(c) = %d\n",sizeof(c));
    system("pause");
    return 0;
}


