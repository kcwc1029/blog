/*   ch8_25.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char course[][50] = {"AI �ƾ�",
					     "Python",
					     "�{�N���z"};					
    int len;
	len = sizeof(course) / sizeof(course[0]);
	printf("�r��ƶq = %d\n", len);
    system("pause");
    return 0;
}


