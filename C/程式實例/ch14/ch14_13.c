/*   ch14_13.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    enum Machine 
	{
		running=1, maintenance, failed	
	} state;
    
    printf("�п�J�����Ͳ����A \n");
    printf("1. �Ͳ���\n");
    printf("2. ���פ�\n");
    printf("3. �l�a\n= ");
	scanf("%d",&state); 
    switch (state)
    {
        case running:
        	printf("�������`�Ͳ���\n");
            break;
        case maintenance :
        	printf("�������`���פ�\n");
            break;
        case failed :
        	printf("�����l�a\n");
            break;    
        default: 
        	printf("��J���~\n");
          	break;
    }
    system("pause");
    return 0;
}


