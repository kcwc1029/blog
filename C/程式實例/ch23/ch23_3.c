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

    ptr = NULL;              /* 最初化根節點指標 */
    printf("使用陣列資料建立二元樹 \n");
    for ( i = 0; i < 6; i++ )
    {
       ptr = create_btree(ptr,arr[i]);
       printf("%d\n",arr[i]);
    }
    printf("使用後序postorder列印二元樹\n");
    postorder(ptr);
    system("pause");
    return 0;
}
/* 建立二元樹 */
node *create_btree(node *root, int val)
{
    node *newnode, *current, *back;

    newnode = (node *) malloc(sizeof(node)); /*建立新節點*/ 
    newnode->data = val;                    /*存入節點值*/ 
    newnode->left = NULL;  /* 新節點左子樹指標指向 NULL */ 
    newnode->right = NULL; /* 新節點右子樹指標指向 NULL */
    if ( root == NULL )            /* 新節點是根節點    */
    {
       root = newnode;
       return root;
    }
    else                            /* 新節點是其它位置 */
    {
       current = root; /*由根節點開始找尋新節點正確位置 */ 
       while ( current != NULL )
       {
          back = current;
          if ( current->data > val )/*如果節點值大於插入值*/ 
             current = current->left;   /* 指標往左子樹走 */ 
          else
             current = current->right;  /* 指標往右子樹走 */
       }
       if ( back->data > val )  /* 如果葉節點值大於插入值 */ 
          back->left = newnode; /*新節點放在葉節點的左子樹*/ 
       else                     /* 否則 */ 
          back->right = newnode;/*新節點放在葉節點的右子樹*/
    }
    return root;
}
/* 後序列印二元樹 */ 
void postorder(node *root)
{
    if ( root != NULL )
    {
       postorder(root->left);   /* 先檢查左邊子樹 */ 
       postorder(root->right);  /* 再檢查右邊子樹 */
       printf("%d\n",root->data);
    }
}



