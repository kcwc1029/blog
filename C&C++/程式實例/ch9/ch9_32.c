/*   ch9_32.c                   */
#include <stdio.h>
#include <stdlib.h>
int sum(int n)
{
    int i, sum;

    sum = 0;
    for ( i = 1; i <= n; i++ )
       sum += i;
    return sum;
}
int main()
{
    int n;

    printf("�п�J�t�C�[�`�� : ");
    scanf("%d",&n);
    printf("�q 1 �[�� %d = %d\n",n,sum(n));
    system("pause");
    return 0;
}


