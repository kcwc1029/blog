/*   ch11_23.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[] = {3, 6, 7, 5, 9};
    int len;		/* �}�C���� */ 
    
    printf("�}�C���� = %d\n",sizeof(num));	
    len = sizeof(num) / sizeof(num[0]);
	printf("�}�C�����Ӽ� = %d\n",len);
	printf("�}�C����}   = %X\n",num);
    system("pause");
    return 0;
}


