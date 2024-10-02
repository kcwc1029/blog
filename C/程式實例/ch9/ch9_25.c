/*   ch9_25.c                   */
#include <stdio.h>
#include <stdlib.h>
void display(int num[], int len)
{
    int i;
	printf("num 陣列位址 = %p\n",num);
    for ( i = 0; i < len; i++ )
       printf("%d\n", num[i]);
}
int main()
{
    int data[] = {5, 6, 7, 8, 9};
    
    int len = sizeof(data) / sizeof(data[0]); /* 陣列長度 */ 
    printf("data陣列位址 = %p\n",data);
    printf("輸出陣列內容\n");
    display(data,len);
    system("pause");
    return 0;
}



