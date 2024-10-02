/*   ch9_26.c                   */
#include <stdio.h>
#include <stdlib.h>
void display(int num[], int len)
{
    int i;
    printf("display函數輸出\n");
	printf("num 陣列位址 = %p\n",num);
    for ( i = 0; i < len; i++ )
       printf("num[%d]=%d \t address=%p\n",i,num[i],&num[i]);
}
int main()
{
    int data[] = {5, 6, 7, 8, 9};
    int i;
    
    int len = sizeof(data) / sizeof(data[0]); /* 陣列長度 */ 
    printf("main函數輸出\n");
    printf("data陣列位址 = %p\n",data);
    for ( i = 0; i < len; i++ )
       printf("data[%d]=%d \t address=%p\n",i,data[i],&data[i]);
    display(data,len);
    system("pause");
    return 0;
}



