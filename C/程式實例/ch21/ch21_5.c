/*   ch21_5.c                  */
#include <stdlib.h>
#include <stdio.h>
struct list                 /* 宣告動態資料結構 */ 
{
    int data;
    struct list *next;
};
typedef struct list node;
int main()
{
    node *ptr;

    ptr = (node *) malloc(sizeof(node)); /* 取得記憶體空間 */ 
    ptr->data = 5;                    /* 設定第 1 個節點值 */ 
    ptr->next = NULL;
    /* 接下來取得第 2 個節點記憶體空間 */ 
    ptr->next = (node *) malloc(sizeof(node));
    ptr->next->data = 10;             /* 設定第 2 個節點值 */
    ptr->next->next = NULL;
    printf("第 1 個節點值是 = %d\n",ptr->data);
    printf("第 2 個結點值是 = %d\n",ptr->next->data);
    system("pause");
    return 0;
}


