/*   ch22_2.c                  */
#include <stdlib.h>
#include <stdio.h>
struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue node;
node *enqueue(node *, int);
node *dequeue(node *, int *);
/* 將資料存入佇列 */ 
node *enqueue(node *queue, int value)
{
    node *newnode;

    newnode = (node *) malloc(sizeof(node));
    newnode->data = value;  /* 將資料存入新建佇列節點    */ 
    newnode->next = NULL;
    if ( queue != NULL )    /* 移動queue(ptrb)指向新結點 */
    {
       queue->next = newnode;
       queue = queue->next;
    }
    else
       queue = newnode;     /* 建第ㄧ個節點的設定       */
    return queue;
}
/* 讀取佇列資料 */ 
node *dequeue(node *queue, int *value)
{
    node *dequeuenode;

    dequeuenode = queue;
    *value = dequeuenode->data;  		/* 取得佇列資料 */ 
    queue = queue->next; /* 重新設定queue(ptrf)指標位置 */ 
    free(dequeuenode);   /* 取得資料後即釋回記憶空間    */ 
    return queue;
}
int main()
{
    int   arr[] = { 3, 12, 8, 9, 11 };
    node *ptrb, *ptrf;
    int   val, i;

    ptrf = NULL;    			/* 最初化佇列起始節點指標 */
    ptrb = ptrf;    			/* 最初化佇列末端節點指標 */
    printf("使用 enqueue 建立佇列 \n");
    for ( i = 0; i < 5; i++ )
    {
       ptrb = enqueue(ptrb,arr[i]);
       if ( ptrf == NULL )     /* 成立代表建第ㄧ個佇列節點 */ 
          ptrf = ptrb; /*建第ㄧ個節點時兩個指標指向相同位置*/ 
       printf("%d\n",arr[i]);
    }
    printf("使用 dequeue 列印佇列 \n");
    for ( i = 0; i < 5; i++ )
    {
       ptrf = dequeue(ptrf,&val);
       printf("%d\n",val);
    }
    system("pause");
    return 0;
}


