/*   ch3_26.c                  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z;

    x = y = z = 0;
/* ���� ++ �B��l */
    x = ++y + ++z;
    printf("�� 11 �C���G %d %d %d\n",x,y,z);
    x = y++ + z++;
    printf("�� 13 �C���G %d %d %d\n",x,y,z);
/* ���� -- �B��l */
    x = y = z = 0;
    x = --y + --z;
    printf("�� 17 �C���G %d %d %d\n",x,y,z);
    x = y-- + z--;
    printf("�� 19 �C���G %d %d %d\n",x,y,z);
    system("pause");
    return 0;
}
