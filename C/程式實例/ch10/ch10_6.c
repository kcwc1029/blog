/*   ch10_6.c                   */
#include <stdio.h>
#include <stdlib.h>
#define  TRUE   1
#define  FALSE  0
#define  SQUARE  n*n
int main()
{
    int n;
    int again = TRUE;

    printf("�p�G��J�j�� 50 �{���N�۰ʵ��� \n");
    while ( again )   /* �p�G�p��ε��� 50 �{���~�� */ 
    {
       	printf("�п�J�ƭ� ==> ");
       	scanf("%d",&n);      
       	if ( n <= 50 )
	   		printf("����ȬO = %d\n",SQUARE);  
       	else
       	{
       		again = FALSE;  /* ��J�j�� 50 �h�]�w */
       		printf("�{������\n");
		}    	 
    }
    system("pause");
    return 0;
}



