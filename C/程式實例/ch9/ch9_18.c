/*   ch9_18.c                  */
#include <stdio.h>
#include <stdlib.h>
void palindrome(int n);
int main()
{
    int i = 5;     /* �]�w��J 5 �Ӧr�� */ 
    
    printf("�п�J�t 5 �Ӧr�����r��\n");
    palindrome(i);
    printf("\n");
    system("pause");
    return 0;
}
/* Ū���r���M�ϦV��X�r�� */ 
void palindrome(int n)
{
    char next;

    if ( n <= 1 ) 	/* Ū��̫᣸�Ӧr��������|����  */ 
    {
       next = getche();
       printf("\n");
       putchar(next);
    }
    else
    {
       next = getche();   /* Ū�r��   */ 
       palindrome(n-1);    /* �I�s�ۤv */ 
       putchar(next);
    }
}


