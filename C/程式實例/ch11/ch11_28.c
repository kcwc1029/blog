/*   ch11_28.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[10];
    int *ptr = num; 				
    int i, count;
	int sum = 0;
    	
    printf("�п�J�}�C�����Ӽ� : ");
    scanf("%d", &count);    
    for (i = 0; i < count; i++)
    {
    	printf("�п�J�}�C�������e : ");   	
    	scanf("%d", ptr++);
	}    	
	ptr = num;		/* �N���в��^�}�C�ҩl��m */ 
	for (i = 0; i < count; i++)
		sum += *ptr++;
	printf("�`�M = %d\n", sum);	    	 	 
    system("pause");
    return 0;
}


