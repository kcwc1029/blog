/*   ch21_14.c                  */
#include <stdlib.h>
#include <stdio.h>
struct list                 /* �ŧi�ʺA��Ƶ��c */ 
{
    int data;
    struct list *next;
};
typedef struct list node;
typedef node *link;
int main()
{
    link  ptr;

    ptr = (link) malloc(sizeof(node)); /* ���o�O����Ŷ� */ 
    ptr->data = 5;                  /* �]�w�� 1 �Ӹ`�I�� */ 
    ptr->next = NULL;
    /* ���U�Ө��o�� 2 �Ӹ`�I�O����Ŷ� */ 
    ptr->next = ( link ) malloc(sizeof(node));
    ptr->next->data = 10;           /* �]�w�� 2 �Ӹ`�I�� */
    ptr->next->next = NULL;
    printf("�� 1 �Ӹ`�I�ȬO = %d\n",ptr->data);
    printf("�� 2 �ӵ��I�ȬO = %d\n",ptr->next->data);
    system("pause");
    return 0;
}


