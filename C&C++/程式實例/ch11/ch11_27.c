/*   ch11_27.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[10];
    int *ptr; 				
    int i, count;
    
    ptr = num; 		
    printf("�п�J�}�C�����Ӽ� : ");
    scanf("%d", &count);    
    for (i = 0; i < count; i++)
    {
    	printf("�п�J�}�C�������e : ");   	
    	scanf("%d", ptr++);
	}    	
	ptr = num;		/* �N���в��^�}�C�_�l��m */ 
	for (i = 0; i < count; i++)
		printf("��X[%d] : %d\n", i, *(ptr+i));	    	 	 
    system("pause");
    return 0;
}


