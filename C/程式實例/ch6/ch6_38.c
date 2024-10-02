/*   ch6_38.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float height, dist;
    int i;
    height = 100;
	dist = 100; 
    height = height / 2;        /* 第一次反彈高度 */
    for(i = 2; i <= 10; i++)
    {
        dist += 2 * height;
        height = height / 2;
    }
    printf("第10次落地行經距離 %6.3f\n",dist);
    printf("第10次落地反彈高度 %6.3f\n",height);
    system("pause");
    return 0;
}


