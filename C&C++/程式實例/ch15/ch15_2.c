/*   ch15_2.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    
    while ( 1 )
    {
    	printf("�п�J���N�r�� : ");
    	scanf(" %c", &ch);
    	if ( isalpha(ch) )
    		printf("'%c' �O�ݩ�^��r��\n", ch);
    	else
    	{
    		printf("'%c' ���O�ݩ�^��r��\n", ch);
    		break;
		}
	} 
    system("pause");
    return 0;
}


