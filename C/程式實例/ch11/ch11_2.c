/*   ch11_2.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 6;
    float b = 3.14;
    char c = 'K';
    printf(" a = %d �� address = %p\n",a, &a);
    printf("sizeof(a) = %d\n",sizeof(a));
    printf(" b = %f �� address = %p\n",b, &b);
    printf("sizeof(b) = %d\n",sizeof(b));
    printf(" c = %c �� address = %p\n",c, &c);
    printf("sizeof(c) = %d\n",sizeof(c));
    system("pause");
    return 0;
}


