/*   ch12_14.c                  */
#include <stdio.h>
#include <stdlib.h>
void swap(int *, int *);
void exchange(int *, int *, int *);
int main()
{
    int x, y, z;
    int *px, *py, *pz;
    
    px = &x;
    py = &y;
    pz = &z;
    printf("請輸入 3 個數字 : ");
    scanf("%d %d %d", &x, &y, &z);
    exchange(px, py, pz);
    printf("%d \t %d \t %d \n", x, y, z);
    system("pause");
    return 0;
}
void exchange(int *p1, int *p2, int *p3)
{
	if (*p1 > *p2)
		swap(p1, p2);
	if (*p1 > *p3)
		swap(p1, p3);
	if (*p2 > *p3)
		swap(p2, p3);
}
void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}




