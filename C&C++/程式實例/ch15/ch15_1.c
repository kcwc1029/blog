/*   ch15_1.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    printf("�п�J���N�r�� : "); 
    scanf("%c", &ch);
    if ( isalnum(ch) )
    	printf("%c �O�ݩ�^��r���Ϊ��ԧB�Ʀr\n", ch);
    else
    	printf("%c ���ݩ�^��r���Ϊ��ԧB�Ʀr\n", ch);
    system("pause");
    return 0;
}


