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
    printf("��ƥ洫�e\n");
    printf("x = %d,\t y = %d\n",x, y);
    ptrx = &x;
    ptry = &y;
    tmp = *ptrx; 		/* �Ȯ��x�s *ptrx      */ 
    *ptrx = *ptry; 		/* �]�w *ptry �� *ptrx */ 
    *ptry = tmp; 		/* �]�w tmp �� *ptry   */
    printf("��ƥ洫��\n");
    printf("x = %d,\t y = %d\n",x, y);      
    system("pause");
    return 0;
}


