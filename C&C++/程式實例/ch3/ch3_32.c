/*   ch3_32.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int h, f;
	int chicken, rabbit;
	
	printf("�п�J�Y���ƶq : ");
	scanf("%d", &h);
	printf("�п�J�}���ƶq : ");
	scanf("%d", &f);
	rabbit = (int) (f / 2 - h);
	chicken = (int) (2 * h - f / 2);
    printf("���� %2d ��, �ߦ� %d ��\n", chicken, rabbit);
    system("pause");
    return 0;
}


