/*   ch7_6.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[5];
    float b[5];
    double c[5];		
	printf("a[5]陣列空間 = %d 位元組\n", sizeof(a));
	printf("b[5]陣列空間 = %d 位元組\n", sizeof(b));
	printf("c[5]陣列空間 = %d 位元組\n", sizeof(c));
    system("pause");
    return 0;
}


