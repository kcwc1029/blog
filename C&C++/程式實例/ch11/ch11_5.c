/*   ch11_5.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;
    int *i, *j;
    
    printf("�п�J a, b ���� : ");
    scanf("%d %d",&a, &b);
    i = &a;
    j = &b;
    printf("�ܼ� a ���� = %d\n", a);
    printf("�ܼ� a ����} = %d\n", &*i); 	 
    printf("�ܼ� a ����} = %d\n", &a);
    printf("�ܼ� b ���� = %d\n", b);
    printf("�ܼ� b ����} = %d\n", &*j);		
    printf("�ܼ� b ����} = %d\n", &b);	    
    system("pause");
    return 0;
}


