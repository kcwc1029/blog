/*   ch6_37.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int password;
    
    for (i=1; i<=3; i++)
    {
    	printf("�п�J�K�X : ");
    	scanf("%d", &password);
    	if (password == 12345)
    	{
    		printf("�K�X���T, �w��i�J�t��\n");
    		break;
    	}
    	else
    		if (i == 3 && password != 12345)
    			printf("�K�X���~ 3 ��, �Ц��d�x���s�ӽбK�X\n");
	} 		     
    system("pause");
    return 0;
}


