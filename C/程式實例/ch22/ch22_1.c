/*   ch22_1.c                  */
#include <stdlib.h>
#include <stdio.h>
struct stacks
{
    int data;      
    struct stacks *next;
};
typedef struct stacks node;
node *push(node *, int);
node *pop(node *, int *);
/* �N��Ʃ�J���| */ 
node *push(node *stack, int value)
{
    node  *newnode;

    newnode = (node *) malloc(sizeof(node));
    newnode->data = value; /* �]�w�s���|�I���� */ 
    newnode->next = stack; /*�s���|���Ы��V����|����*/ 
    stack = newnode;       /*�]�w���V�s���|���ݫ���  */ 
    return stack;          /*�Ǧ^���V���|���ݫ���    */
}
/* �Ѱ��|���o��� */ 
node *pop(node *stack, int *value)
{
    node *top;

    top = stack;
    stack = stack->next;
    *value = top->data;    /* ���o���|���ݭ�               */ 
    free(top);             /* ���^��̳��ݪ����|�`�O�ЪŶ� */ 
    return stack;          /* �Ǧ^���V���|���ݫ���         */ 
}
int main()
{
    int   arr[] = { 3, 12, 8, 9, 11 };
    node  *ptr;
    int   val, i;

    ptr = NULL;
    printf("���ǦC�L��ư}�C \n");
    /* �N�}�C��Ʃ�J���|�P�ɰ���C�L */ 
    for ( i = 0; i < 5; i++ )
    {
       ptr = push(ptr,arr[i]);  
       printf("%d\n",arr[i]);
    }
    printf("�ϦV�C�L���ư}�C \n");
    /* ���o���|��ƦP�ɰ���C�L */ 
    for ( i = 0; i < 5; i++ )
    {
       ptr = pop(ptr,&val);
       printf("%d\n",val);
    }
    system("pause");
    return 0;
}



