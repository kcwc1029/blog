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
/* 列印鏈結串列函數 */ 
void print_list(node *pointer)
{
    while ( pointer )
    {
       printf("%d\n",pointer->data);
       pointer = pointer->next;
    }
}
/* 將陣列轉成鏈結串列函數 */ 
node *create_list(int array[],int num)
{
    node *first, *cur, *newnode;
    int  i;
/* first 指向串列的第一個節點 */ 
    first = (node *) malloc(sizeof(node));
    first->data = array[0]; 	/* 第一筆資料   */ 
    cur = first;            	/* 移動暫時指標 */ 
    for ( i = 1; i < num; i++ )
    {
       newnode = (node *) malloc(sizeof(node));
       newnode->next = NULL;
       newnode->data = array[i];
       cur->next = newnode;     /* 舊節點指標指向新節點 */ 
       cur = newnode;           /* 移動暫時指標         */
    }
    return first;
}


