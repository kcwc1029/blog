/*   ch7_9.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int Size = 5;
    int score[Size]; 		/* ���]�̦h�O 5 �Ӿǥ� */ 
	int i,sum;
    float ave;
    i = 0;
    sum = 0;
    printf("��J 0 �N���J����\n");
    do
    {
       if (i >= Size)
       {
          printf("�}�C�w��\n");
          i += 1; 			/* 25�C�|�� 1 */ 
          break;
	   }
       printf("�п�J���� ==> ");
       scanf("%d",&score[i]);
       sum += score[i];
    } while (score[i++] > 0);
    ave = (float) sum / (i - 1); 
    printf("�������ƬO %6.2f \n",ave);
    system("pause");
    return 0; 
}


