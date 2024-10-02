/*   ch21_10.c                        */
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
void insert(node *, int);

int main()
{
    int arr[] = { 3, 9, 11 };
    node  *ptr, *obj;

    printf("���J�e\n");
    ptr = create_list(arr,3);
    print_list(ptr);
    obj = search(ptr, 9);
    insert(obj, 10);
    printf("���J��\n");
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
/* �bptr�`�I�᭱�@�ӷs���`�I, ���J�ƭȬO data */ 
void insert(node *ptr,int data)
{
   node *newnode;
   newnode = (node *) malloc(sizeof(node));	/* ���o�s�`�I */
   newnode->data = data;		   /* �]�w�s�`�I��data    */
   newnode->next = ptr->next;	   /* �s�`�I���Vptr��next */
   ptr->next = newnode;			   /* ptr��next���V�s�`�I */
}


