/*   ch7_8.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int score[10]; 		/* ���]�̦h�O 10 �Ӿǥ� */ 
	int i,sum;
    float ave;
    i = 0;
    sum = 0;
    printf("��J 0 �N���J����\n");
    do
    {
       printf("�п�J���� ==> ");
       scanf("%d",&score[i]);
       sum += score[i];
    } while (score[i++] > 0);
    ave = (float) sum / (i - 1); 
    printf("�������ƬO %6.2f \n",ave);
    system("pause");
    return 0; 
}


