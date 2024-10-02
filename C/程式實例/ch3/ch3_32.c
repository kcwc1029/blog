/*   ch3_32.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int h, f;
	int chicken, rabbit;
	
	printf("請輸入頭的數量 : ");
	scanf("%d", &h);
	printf("請輸入腳的數量 : ");
	scanf("%d", &f);
	rabbit = (int) (f / 2 - h);
	chicken = (int) (2 * h - f / 2);
    printf("雞有 %2d 隻, 兔有 %d 隻\n", chicken, rabbit);
    system("pause");
    return 0;
}


