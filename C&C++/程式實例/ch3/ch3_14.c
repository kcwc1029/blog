/*   ch3_14.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 10;
    float j = 123.56;

    printf("�榡�ƿ�X�K�줸\n");
    printf("/%o/\n",i);
    printf("/%-8o/\n",i);
    printf("�榡�ƿ�X�Q���줸\n");
    printf("/%x/\n",i);
    printf("/%8x/\n",i);
    printf("�榡�ƿ�X���a���t���ƭ�\n");
    printf("/%u/\n",i);
    printf("/%8u/\n",i);
    printf("�榡�ƿ�X��ǲŸ�\n");
    printf("/%e/\n",j);
    printf("/%8.3e/\n",j);
    system("pause");
    return 0;
}


