/*   ch6_11.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int digit,num;

    printf("�п�J���N��� \n==> ");
    scanf("%d",&num);
    printf("��ƪ��ۤϿ�X \n==> ");
    while ( num != 0 )
    {
       digit = num % 10;
       num = num / 10;
       printf("%d",digit);
    }
    printf("\n");
    system("pause");
    return 0;
}


