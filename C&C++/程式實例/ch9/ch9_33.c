/*   ch9_33.c                   */
#include <stdio.h>
#include <stdlib.h>
int isPrime(int n)
{
    int i;
    for (i = 2; i < n; i++)
    	if (n % i == 0)
    		return 0;
    return 1;
}
int main()
{
    int num;

    printf("�п�J�j�� 1 ����ư����� = ");
    scanf("%d",&num);
    if (isPrime(num)) 
    	printf("%d �O���\n", num);
    else
    	printf("%d ���O���\n", num);
    system("pause");
    return 0;
}


