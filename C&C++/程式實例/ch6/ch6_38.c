/*   ch6_38.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float height, dist;
    int i;
    height = 100;
	dist = 100; 
    height = height / 2;        /* �Ĥ@���ϼu���� */
    for(i = 2; i <= 10; i++)
    {
        dist += 2 * height;
        height = height / 2;
    }
    printf("��10�����a��g�Z�� %6.3f\n",dist);
    printf("��10�����a�ϼu���� %6.3f\n",height);
    system("pause");
    return 0;
}


