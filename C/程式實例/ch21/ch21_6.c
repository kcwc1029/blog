/*   ch21_6.c                  */
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
	node a, b;
    node *ptr;
    ptr = &a;
    ptr->data = 5;          /* 設定第 1 個節點值 */ 
    ptr->next = NULL;
    /* 接下來取得第 2 個節點記憶體空間 */ 
    ptr->next = &b;
    ptr->next->data = 10;   /* 設定第 2 個節點值 */
    ptr->next->next = NULL;
    printf("address=%X\t", &a);
    printf("data=%d\t", ptr->data);
    printf("next=%X\n",ptr->next);
    printf("address=%X\t", &b);
    printf("data=%d\t",ptr->next->data);
    printf("next=%X\n",ptr->next->next);
    system("pause");
    return 0;
}


