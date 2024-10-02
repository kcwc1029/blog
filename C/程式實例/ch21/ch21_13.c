/*   ch21_13.c                 */
#include <stdlib.h>
#include <stdio.h>
struct list            /* 雙向鏈結串列宣告 */ 
{
    int data;
    struct list *front;  /* 指向下ㄧ個節點 */ 
    struct list *back;   /* 指向前ㄧ個節點 */ 
};
typedef struct list node;
int main()
{
/* cur是目前節點指標         */
/* ptr是固定在第一個節點指標 */ 
    node  *cur, *ptr, *newnode;
    int   num, i;
    
    printf("請輸入 3 筆資料 \n");
    for ( i = 0; i < 3; i++ )
    {
    	newnode = (node *) malloc(sizeof(node));
    	scanf("%d",&num);
    	if (i == 0) 		/* 建立第一個節點        */ 
    	{	
    		newnode->back = NULL;
    		newnode->front = NULL;
    		newnode->data = num;
    		cur = newnode;   /* 目前指標位置 		 */
			ptr = newnode; 	 /* 固定不變串列開始位置 */ 
		} 
       	if ( i > 0 ) 		 /* 建立其他節點         */ 
       	{
          	newnode->front = cur;
          	newnode->back = NULL;
          	newnode->data = num;
          	cur->back = newnode;
          	cur = newnode;  /* cur 指向所建的節點 */ 
       	}
    }
    printf("反向列印雙向鏈結串列\n");
    while ( cur ) 			/* cur 偉往前輸出     */ 
    {
       printf("串列值 ==> %d\n",cur->data);
       cur = cur->front;
    }
    printf("順序列印雙向鏈結串列\n");
    cur = ptr; 				/* cur 移到最前節點 */ 
    while ( cur )
    {
       printf("串列值 ==> %d\n",cur->data);
       cur = cur->back;
    }
    system("pause");
    return 0;
}


