/*   ch9_9.c                   */
#include <stdio.h>
#include <stdlib.h>
int add(int a, int b)
{
	return a + b; 
}
int main()
{
    int x, y;
    int total = 0;

    printf("請輸入兩數值 \n ==> ");
    scanf("%d %d",&x,&y);
    total = add(x, y);
    printf("%d + %d = %d\n", x, y, total);
    system("pause");
    return 0;
}


