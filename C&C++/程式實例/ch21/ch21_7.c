/*   ch21_7.c                  */
#include <stdlib.h>
#include <stdio.h>
struct list               /* 宣告動態資料結構 */ 
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
    ptr = head;           /* 將指標指向第一個節點 */ 
    printf("請輸入 5 筆資料 \n");
    for ( i = 0; i <= 4; i++ )
    {
       scanf("%d",&num);
       ptr->data = num;   /* 設定節點值 */ 
       ptr->next = (node *) malloc(sizeof(node));
       if ( i == 4 )  /* 如果是第 5 筆資料將指標指向 NULL */ 
          ptr->next = NULL;
       else           /* 否則將指標指向下一個節點         */ 
          ptr = ptr->next;
    }
    printf("順序列印串列 \n");
    ptr = head;           /* 將指標指向第一個節點     */
    while ( ptr != NULL ) /* 如果不是指向 NULL 則列印 */  
    {
       printf("串列值 ==> %d\n",ptr->data);
       ptr = ptr->next;
    }
    system("pause");
    return 0;
}


