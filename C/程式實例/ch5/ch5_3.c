/*   ch5_3.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    printf("請輸入整數值 : ");
    scanf("%d", &num);
    if (num < 0)
        num = -num;
    printf("絕對值是 %d\n", num);
    system("pause");
    return 0;
}


