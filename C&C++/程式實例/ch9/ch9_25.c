/*   ch9_25.c                   */
#include <stdio.h>
#include <stdlib.h>
void display(int num[], int len)
{
    int i;
	printf("num �}�C��} = %p\n",num);
    for ( i = 0; i < len; i++ )
       printf("%d\n", num[i]);
}
int main()
{
    int data[] = {5, 6, 7, 8, 9};
    
    int len = sizeof(data) / sizeof(data[0]); /* �}�C���� */ 
    printf("data�}�C��} = %p\n",data);
    printf("��X�}�C���e\n");
    display(data,len);
    system("pause");
    return 0;
}



