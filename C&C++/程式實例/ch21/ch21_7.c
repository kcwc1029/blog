/*   ch21_7.c                  */
#include <stdlib.h>
#include <stdio.h>
struct list               /* �ŧi�ʺA��Ƶ��c */ 
{
    int data;
    struct list *next;
};
typedef struct list node;
int main()
{
    node  *ptr, *head;
    int   num,i;

    head = (node *) malloc(sizeof(node));  
    ptr = head;           /* �N���Ы��V�Ĥ@�Ӹ`�I */ 
    printf("�п�J 5 ����� \n");
    for ( i = 0; i <= 4; i++ )
    {
       scanf("%d",&num);
       ptr->data = num;   /* �]�w�`�I�� */ 
       ptr->next = (node *) malloc(sizeof(node));
       if ( i == 4 )  /* �p�G�O�� 5 ����ƱN���Ы��V NULL */ 
          ptr->next = NULL;
       else           /* �_�h�N���Ы��V�U�@�Ӹ`�I         */ 
          ptr = ptr->next;
    }
    printf("���ǦC�L��C \n");
    ptr = head;           /* �N���Ы��V�Ĥ@�Ӹ`�I     */
    while ( ptr != NULL ) /* �p�G���O���V NULL �h�C�L */  
    {
       printf("��C�� ==> %d\n",ptr->data);
       ptr = ptr->next;
    }
    system("pause");
    return 0;
}


