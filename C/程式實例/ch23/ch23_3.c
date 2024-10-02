/*   ch23_3.c                  */
#include <stdlib.h>
#include <stdio.h>
struct tree
{
    int data;
    struct tree *left, *right;
};
typedef struct tree node;
node *create_btree(node *, int);
void postorder(node *);
int main()
{
    int arr[] = { 10, 21, 5, 9, 13, 28 };
    node *ptr;
    int i;

    ptr = NULL;              /* �̪�Ʈڸ`�I���� */
    printf("�ϥΰ}�C��ƫإߤG���� \n");
    for ( i = 0; i < 6; i++ )
    {
       ptr = create_btree(ptr,arr[i]);
       printf("%d\n",arr[i]);
    }
    printf("�ϥΫ��postorder�C�L�G����\n");
    postorder(ptr);
    system("pause");
    return 0;
}
/* �إߤG���� */
node *create_btree(node *root, int val)
{
    node *newnode, *current, *back;

    newnode = (node *) malloc(sizeof(node)); /*�إ߷s�`�I*/ 
    newnode->data = val;                    /*�s�J�`�I��*/ 
    newnode->left = NULL;  /* �s�`�I���l����Ы��V NULL */ 
    newnode->right = NULL; /* �s�`�I�k�l����Ы��V NULL */
    if ( root == NULL )            /* �s�`�I�O�ڸ`�I    */
    {
       root = newnode;
       return root;
    }
    else                            /* �s�`�I�O�䥦��m */
    {
       current = root; /*�Ѯڸ`�I�}�l��M�s�`�I���T��m */ 
       while ( current != NULL )
       {
          back = current;
          if ( current->data > val )/*�p�G�`�I�Ȥj�󴡤J��*/ 
             current = current->left;   /* ���Щ����l�� */ 
          else
             current = current->right;  /* ���Щ��k�l�� */
       }
       if ( back->data > val )  /* �p�G���`�I�Ȥj�󴡤J�� */ 
          back->left = newnode; /*�s�`�I��b���`�I�����l��*/ 
       else                     /* �_�h */ 
          back->right = newnode;/*�s�`�I��b���`�I���k�l��*/
    }
    return root;
}
/* ��ǦC�L�G���� */ 
void postorder(node *root)
{
    if ( root != NULL )
    {
       postorder(root->left);   /* ���ˬd����l�� */ 
       postorder(root->right);  /* �A�ˬd�k��l�� */
       printf("%d\n",root->data);
    }
}



