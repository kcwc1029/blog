/*   ch9_36.c                  */
#include <stdio.h>
#include <stdlib.h>
int gcd(int, int);
int main()
{
    int x, y;
    int gc;

    printf("�п�J 2 �ӥ���� \n==> ");
    scanf("%d %d",&x,&y);
    gc = gcd(x,y);
    printf("�̤j�����ƬO %d \n",gc);
    system("pause");
    return 0;
}
int gcd(int x, int y)
{
	int tmp;
	while (y != 0)
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}


