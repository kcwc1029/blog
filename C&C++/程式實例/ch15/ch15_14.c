/*   ch15_14.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch[] = {'!','7','@','A','&','p'};
    int bool[7];
    int i, size;
    
    size = sizeof(ch) / sizeof(ch[0]);
    for (i = 0; i < size; i++)
    	bool[i] = isalnum(ch[i]);
    for (i = 0; i < size; i++)
    {
    	if (bool[i] != 0)
    		printf("'%c' �ݩ�^��r���Ϊ��ԧB�Ʀr\n", ch[i]);
    	else
    		printf("'%c' ���ݩ�^��r���Ϊ��ԧB�Ʀr\n", ch[i]);
    	
	}
    system("pause");
    return 0;
}


