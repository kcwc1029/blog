/*   ch3_19_3.c                    */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    char ch;

    printf("�п�J 1 �Ӿ�� \n==>");
    scanf("%d",&i);
    printf("�п�J 1 �Ӧr�� \n==>");
    scanf(" %c",&ch);  /* �i���L���i�C�L�r�� */ 
    printf("��ƬO=%d, Ascii�X�ȬO=%d, �r���O=%c \n",i,ch,ch);
    system("pause");
    return 0; 
}


