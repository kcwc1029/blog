/*   ch21_6.c                  */
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
	node a, b;
    node *ptr;
    ptr = &a;
    ptr->data = 5;          /* �]�w�� 1 �Ӹ`�I�� */ 
    ptr->next = NULL;
    /* ���U�Ө��o�� 2 �Ӹ`�I�O����Ŷ� */ 
    ptr->next = &b;
    ptr->next->data = 10;   /* �]�w�� 2 �Ӹ`�I�� */
    ptr->next->next = NULL;
    printf("address=%X\t", &a);
    printf("data=%d\t", ptr->data);
    printf("next=%X\n",ptr->next);
    printf("address=%X\t", &b);
    printf("data=%d\t",ptr->next->data);
    printf("next=%X\n",ptr->next->next);
    system("pause");
    return 0;
}


