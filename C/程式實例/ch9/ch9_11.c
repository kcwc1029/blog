/*   ch9_11.c                   */
#include <stdio.h>
#include <stdlib.h>
float mypow(float base, int n)
{
	int i;
	float rtn = 1.0;
	for ( i = 0; i < n; i++ )
		rtn *= base;
	return rtn; 
}
int main()
{
    float x;
	int y;

    printf("�п�J����   : ");
    scanf("%f",&x);
    printf("�п�J����� : ");
    scanf("%d",&y);
    printf("%f �� %d ���� = %f\n", x, y, mypow(x,y));
    system("pause");
    return 0;
}


