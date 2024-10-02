/*   ch15_2.c                  */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    
    while ( 1 )
    {
    	printf("請輸入任意字元 : ");
    	scanf(" %c", &ch);
    	if ( isalpha(ch) )
    		printf("'%c' 是屬於英文字母\n", ch);
    	else
    	{
    		printf("'%c' 不是屬於英文字母\n", ch);
    		break;
		}
	} 
    system("pause");
    return 0;
}


