/*   ch15_15.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int c_alpha = 0;
    int c_digit = 0;
    char ch;
    
    printf("�п�J���N�^��y�l : ");
    while ( ( ch = getche() ) != '\r' )
    {
    	isalpha(ch) ? (c_alpha++) : ( c_alpha=c_alpha );
		isdigit(ch) ? (c_digit++) : ( c_digit=c_digit );	
	}   
    printf("\n�^��r���Ӽ�   = %d\n",c_alpha);
    printf("\n���ԧB�Ʀr�Ӽ� = %d\n",c_digit);
    system("pause");
    return 0;
}


