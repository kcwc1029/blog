/*   ch21_9.c                        */
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
node *search(node *, int);
int main()
{
    int arr[] = { 3, 12, 8, 9, 11 };
    node  *ptr, *obj;
    int data;

    ptr = create_list(arr,5);
    print_list(ptr);
    printf("�п�J�j�M�Ʀr : ");
    scanf("%d",&data);
    obj = search(ptr, data);
    if (obj != NULL)
    	printf("��� %d �F\n",data);
    else
    	printf("�䤣����w�Ʀr\n");
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
/* �j�M�`�I��� */ 
node *search(node *ptr, int val)
{
   while(ptr != NULL)
   {
      if(ptr->data == val)		/* �O�_���`�I��       */
         return ptr;		  	/* �^�Ǹ`�I��}         */
      else 
         ptr = ptr->next;		/* �N���Ы��V�U�@�Ӹ`�I */
   }
   return NULL;					/* �䤣��h�^�� NULL 	*/
}


