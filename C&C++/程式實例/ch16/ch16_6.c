/*   ch16_6.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int  var,i;
    int  sum = 0;
    float average;

    fp = fopen("out6.txt","w");     /* �}���ɮ� */
    for ( i = 0; i < 5; i++ )
    {
       printf("�п�J��� %d ==>  ",i+1);
       scanf("%d",&var);
       sum += var;
       fprintf(fp,"%d\n",var); /* �N��Ƽg�J�ɮ� */ 
    }
    average = (float) sum / 5.0;     /* �D����   */ 
    fprintf(fp,"�����ȬO %6.2f",average);
    fclose(fp);                      /* �����ɮ� */ 
    system("pause");
    return 0;
}





