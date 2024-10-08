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
    printf("請輸入搜尋數字 : ");
    scanf("%d",&data);
    obj = search(ptr, data);
    if (obj != NULL)
    	printf("找到 %d 了\n",data);
    else
    	printf("找不到指定數字\n");
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
/* 搜尋節點函數 */ 
node *search(node *ptr, int val)
{
   while(ptr != NULL)
   {
      if(ptr->data == val)		/* 是否找到節點值       */
         return ptr;		  	/* 回傳節點位址         */
      else 
         ptr = ptr->next;		/* 將指標指向下一個節點 */
   }
   return NULL;					/* 找不到則回傳 NULL 	*/
}


