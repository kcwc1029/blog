/*   ch12_16.c                  */
#include <stdio.h>
#include <stdlib.h>
void sort(int *, int);
int main()
{
    int n[10];
    int i, num;
    
    printf("�п�J�}�C�����Ӽ� : ");
    scanf("%d", &num);
    printf("�п�J���� : ");
    for (i = 0; i < num; i++)
    	scanf("%d", n+i);		/* �ΰ}�C��}Ū���Ʀr */ 
    sort(n, num);
    printf("�Ƨǵ��G�p�U : \n");
    for (i = 0; i < num; i++)
    	printf("%d\t", n[i]);
    printf("\n");
    system("pause");
    return 0;
}
void sort(int *ptr, int len)
{
	int i, j, tmp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len -1; j++)
			if (*(ptr + j) > *(ptr + j + 1))
			{
				tmp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = tmp;
			}
}





