/*   ch9_26.c                   */
#include <stdio.h>
#include <stdlib.h>
void display(int num[], int len)
{
    int i;
    printf("display��ƿ�X\n");
	printf("num �}�C��} = %p\n",num);
    for ( i = 0; i < len; i++ )
       printf("num[%d]=%d \t address=%p\n",i,num[i],&num[i]);
}
int main()
{
    int data[] = {5, 6, 7, 8, 9};
    int i;
    
    int len = sizeof(data) / sizeof(data[0]); /* �}�C���� */ 
    printf("main��ƿ�X\n");
    printf("data�}�C��} = %p\n",data);
    for ( i = 0; i < len; i++ )
       printf("data[%d]=%d \t address=%p\n",i,data[i],&data[i]);
    display(data,len);
    system("pause");
    return 0;
}



