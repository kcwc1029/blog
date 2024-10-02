/*   ch14_5.c                  */
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
    printf("data.i   = %d\n",data.i);
    printf("=====\n");
    data.f = 8888.666;
    printf("data.i   = %d\n",data.i);
    printf("data.f   = %f\n",data.f);
    printf("=====\n");
    strcpy(data.str, "Programming C");
    printf("data.i   = %d\n",data.i);
    printf("data.f   = %f\n",data.f);
    printf("data.str = %s\n",data.str);
    system("pause");
    return 0;
}



