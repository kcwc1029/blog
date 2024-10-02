/*   ch21_8.c                        */
#include <stdlib.h>
#include <stdio.h>
struct list
{
    int data;
    struct list *next;
};
typedef struct list node;
node *create_list(int *, int);
void print_list(node *);
int main()
{
    int arr[] = { 3, 12, 8, 9, 11 };
    node  *ptr;

    ptr = create_list(arr,5);
    print_list(ptr);
    system("pause");
    return 0;
}
/* �C�L�쵲��C��� */ 
void print_list(node *pointer)
{
    while ( pointer )
    {
       printf("%d\n",pointer->data);
       pointer = pointer->next;
    }
}
/* �N�}�C�ন�쵲��C��� */ 
node *create_list(int array[],int num)
{
    node *first, *cur, *newnode;
    int  i;
/* first ���V��C���Ĥ@�Ӹ`�I */ 
    first = (node *) malloc(sizeof(node));
    first->data = array[0]; 	/* �Ĥ@�����   */ 
    cur = first;            	/* ���ʼȮɫ��� */ 
    for ( i = 1; i < num; i++ )
    {
       newnode = (node *) malloc(sizeof(node));
       newnode->next = NULL;
       newnode->data = array[i];
       cur->next = newnode;     /* �¸`�I���Ы��V�s�`�I */ 
       cur = newnode;           /* ���ʼȮɫ���         */
    }
    return first;
}


