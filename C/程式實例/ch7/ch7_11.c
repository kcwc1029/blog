/*   ch7_11.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int num;
    int flag = 0;			/* �p�G 0 �N��S��� */ 
    int arr[8] = {76, 32, 88, 45, 65, 76, 76, 88};
    
    printf("�п�J�}�C���j�M�� : ");
    scanf("%d", &num);
    for ( i = 0; i < 8; i++ )
		if (arr[i] == num)
		{
			printf("arr[%d] = %d\n", i, num);
			flag = 1;
		}
	if (flag == 0)
		printf("�S�����\n");
    system("pause");
    return 0;
}


