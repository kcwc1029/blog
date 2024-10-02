/*   ch11_11.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 10;
    int y = 20;
    int tmp;
    int *ptrx; 
    int *ptry;
 
    printf("&x=%X\t &y=%X\t &tmp=%X\t &ptrx=%X\t &ptry=%X\n" \
	       ,&x,&y,&tmp,&ptrx,&ptry);   
    printf("資料交換前\n");
    printf("x = %d,\t y = %d\n",x, y);
    ptrx = &x;
    ptry = &y;
    tmp = *ptrx; 		/* 暫時儲存 *ptrx      */ 
    *ptrx = *ptry; 		/* 設定 *ptry 給 *ptrx */ 
    *ptry = tmp; 		/* 設定 tmp 給 *ptry   */
    printf("資料交換後\n");
    printf("x = %d,\t y = %d\n",x, y);      
    system("pause");
    return 0;
}


