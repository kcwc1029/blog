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

    printf("請輸入大於 1 的整數做測試 = ");
    scanf("%d",&num);
    if (isPrime(num)) 
    	printf("%d 是質數\n", num);
    else
    	printf("%d 不是質數\n", num);
    system("pause");
    return 0;
}


