/*   ch9_13.c                   */
#include <stdio.h>
#include <stdlib.h>
int add(int, int); 	/* ��ƭ쫬�ŧi */ 
int mul(int, int);  /* ��ƭ쫬�ŧi */
int main()
{
    int index;
    int x, y;
    
    printf("�п�J 1 �� 2 ��ܭp��覡\n");
    printf("1 : �[�k�B��\n");
    printf("2 : ���k�B��\n=> ");
    scanf("%d",&index);
    printf("�п�J��ƭ� : ");
    scanf("%d %d",&x,&y);
    if (index == 1)
    	printf("%d + %d = %d\n", x, y, add(x, y));
	else if (index == 2)
		printf("%d * %d = %d\n", x, y, mul(x, y));
	else
		printf("�p��覡��ܿ��~\n");
    system("pause");
    return 0;
}
int add(int a, int b)
{
	return a + b; 
}
int mul(int c, int d)
{
	return c * d;
}



