/*   ch10_14.c                   */
#include <stdio.h>
#include <stdlib.h>
#define   MAX
#define   MAXIMUM(x,y)       ( x > y ) ? x : y
#define   MINIMUM(x,y)       ( x > y ) ? y : x
int main()
{
    int a = 10;
    int b = 20;

#ifdef MAX
    printf("較大值是 = %d\n",MAXIMUM(a,b));
#else
    printf("較小值是 = %d\n",MINIMUM(a,b));
#endif
#ifndef MIN
    printf("較小值是 = %d\n",MINIMUM(a,b));
#else
    printf("較大值是 = %d\n",MAXIMUM(a,b));
#endif
#undef MAX
#ifdef MAX
    printf("較大值是 = %d\n",MAXIMUM(a,b));
#else
    printf("較小值是 = %d\n",MINIMUM(a,b));
#endif
#define MIN
#ifndef MIN
    printf("較小值是 = %d\n",MINIMUM(a,b));
#else
    printf("較大值是 = %d\n",MAXIMUM(a,b));
#endif
    system("pause");
    return 0;
}


