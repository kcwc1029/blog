/*   ch12_4.c                  */
#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);
int main()
{
    int j, i;

    i = 5;
    j = 6;
    printf("i address=%X\n",&i);
    printf("j address=%X\n",&j);
    printf("©I¥s swap «e\n");
    printf("i = %d,    j = %d \n",i,j);
    swap(&i,&j);
    printf("©I¥s swap «á\n");
    printf("i = %d,    j = %d \n",i,j);
    system("pause");
    return 0;
}
void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}




