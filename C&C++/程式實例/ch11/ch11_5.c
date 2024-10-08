/*   ch11_5.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;
    int *i, *j;
    
    printf("請輸入 a, b 的值 : ");
    scanf("%d %d",&a, &b);
    i = &a;
    j = &b;
    printf("變數 a 的值 = %d\n", a);
    printf("變數 a 的位址 = %d\n", &*i); 	 
    printf("變數 a 的位址 = %d\n", &a);
    printf("變數 b 的值 = %d\n", b);
    printf("變數 b 的位址 = %d\n", &*j);		
    printf("變數 b 的位址 = %d\n", &b);	    
    system("pause");
    return 0;
}


