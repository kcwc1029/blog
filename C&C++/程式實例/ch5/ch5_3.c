/*   ch5_3.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    printf("�п�J��ƭ� : ");
    scanf("%d", &num);
    if (num < 0)
        num = -num;
    printf("����ȬO %d\n", num);
    system("pause");
    return 0;
}


