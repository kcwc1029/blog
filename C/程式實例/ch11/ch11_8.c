/*   ch11_8.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 6;
    int *ptrint = &x; 
    char ch = 'K';
    char *ptrchar = &ch;
    
    printf("��ƫ��Ъ��� %d\n", sizeof(ptrint));  	 
    printf("�r�����Ъ��� %d\n", sizeof(ptrchar));       
    system("pause");
    return 0;
}


