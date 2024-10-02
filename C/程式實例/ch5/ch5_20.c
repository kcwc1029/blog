/*   ch5_20.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float v;
    
	printf("請輸入火箭速度 : ");
	scanf("%f", &v);
	if (v < 7.9)
        printf("你人造衛星無法進入太空\n");
    else if (v == 7.9)
        printf("人造衛星可以環繞地球作圓形移動\n");
    else if ((v > 7.9) && (v < 11.2))
        printf("人造衛星可以環繞地球作橢圓形移動\n");
    else if ((v >= 11.2) && (v < 16.7))
        printf("人造衛星可以環繞太陽移動\n");
    else 
        printf("人造衛星可以脫離太陽系\n");
    system("pause");
    return 0;
}


