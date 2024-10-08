/*   ch14_4.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union utype
{
    int i;
    float f;
    char str[15];
} data;
int main()
{
    union utype data;
    data.i = 10000;
    data.f = 8888.666;
    strcpy(data.str, "Programming C");
    printf("data.i   = %d\n",data.i);
    printf("data.f   = %f\n",data.f);
    printf("data.str = %s\n",data.str);
    system("pause");
    return 0;
}



