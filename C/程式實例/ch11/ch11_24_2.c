/*   ch11_24_2.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int num[3];
    int i;

    printf("�п�J 3 �Ӿ��\n");
    for (i = 0; i < 3; i++)
    {
    	printf("��J�Ʀr %d = ", i);
    	scanf("%d", num+i);
	}
    for (i = 0; i < 3; i++)
    {
    	printf("��X�Ʀr %d = %d\n", i, num[i]);
	}	
    system("pause");
    return 0; 
}


