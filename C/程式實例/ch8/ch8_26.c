/*   ch8_26.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>>
int main()
{
    char time[][50] = {"09:00 - 09:50",
					   "10:00 - 10:50",
					   "11:00 - 11:50"};
	char course[][50] = {"	AI �ƾ�",
					     "	Python",
					     "	�{�N���z"};					
    int i, len; 
    len = sizeof(time) / sizeof(time[0]);  	/* �r��ƶq */ 
	for ( i = 0; i < len; i++ )
		strcat(time[i],course[i]);
	printf("�ڤ��Ѫ��Ҫ�\n");
	for ( i = 0; i < len; i++ )
		printf("%s\n",time[i]);
    system("pause");
    return 0;
}


