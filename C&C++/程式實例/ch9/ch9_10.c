/*   ch9_10.c                   */
#include <stdio.h>
#include <stdlib.h>
int add(int a, int b)
{
	return a + b; 
}
int main()
{
    int x, y;

    printf("�п�J��ƭ� \n ==> ");
    scanf("%d %d",&x,&y);
    printf("%d + %d = %d\n", x, y, add(x,y));
    system("pause");
    return 0;
}


