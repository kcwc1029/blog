/*   ch16_7.c                  */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE *fp;
    int  i,j,var;

    fp = fopen("data7.txt","r"); /* �}���ɮ� */
    for ( i = 0; i < 5; i++ )
    {
       for ( j = 0; j < 5; j++ )
       {
          fscanf(fp,"%d",&var);
          printf("%c",var);
       }
       printf("\n");
    }
    fclose(fp);  /* �����ɮ� */
    system("pause");
    return 0;
}





