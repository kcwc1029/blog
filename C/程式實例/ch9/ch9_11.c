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

    printf("請輸入底數   : ");
    scanf("%f",&x);
    printf("請輸入次方數 : ");
    scanf("%d",&y);
    printf("%f 的 %d 次方 = %f\n", x, y, mypow(x,y));
    system("pause");
    return 0;
}


