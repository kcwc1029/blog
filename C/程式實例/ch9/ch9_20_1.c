/*   ch9_20_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	
	i = 5;
	printf("�~�h�ܼ� i=%d ����} i=%p\n",i,&i);
	printf("����for�j��e i = %d\n", i);
	{
		int i = 1;
		printf("���h�ܼ� i=%d ����} i=%p\n",i,&i);
		for ( ; i <= 3; i++)
			printf("i = %d\n",i);
	}	
	printf("����for�j��� i = %d\n", i);
    system("pause");
    return 0;   
}



