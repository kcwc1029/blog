/*   ch21_5.c                  */
#include <stdlib.h>
#include <stdio.h>
struct list                 /* �ŧi�ʺA��Ƶ��c */ 
{
    int data;
    struct list *next;
};
typedef struct list node;
int main()
{
    node *ptr;

    ptr = (node *) malloc(sizeof(node)); /* ���o�O����Ŷ� */ 
    ptr->data = 5;                    /* �]�w�� 1 �Ӹ`�I�� */ 
    ptr->next = NULL;
    /* ���U�Ө��o�� 2 �Ӹ`�I�O����Ŷ� */ 
    ptr->next = (node *) malloc(sizeof(node));
    ptr->next->data = 10;             /* �]�w�� 2 �Ӹ`�I�� */
    ptr->next->next = NULL;
    printf("�� 1 �Ӹ`�I�ȬO = %d\n",ptr->data);
    printf("�� 2 �ӵ��I�ȬO = %d\n",ptr->next->data);
    system("pause");
    return 0;
}


