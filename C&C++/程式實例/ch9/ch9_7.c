/*   ch9_7.c                   */
#include <stdio.h>
#include <stdlib.h>
void print_char(int loop, char ch)  
{
    int i;
    for ( i = 0; i < loop; i++)
    	printf("%c",ch);
    printf("\n");
    return;
}
int main()
{
    int times;
    char mychar;

    printf("�п�J���Ʀ��� : ");
    scanf("%d",&times);
    printf("�п�J��X�r�� : ");
    scanf(" %c",&mychar);
    print_char(times, mychar);
    system("pause");
    return 0;
}


