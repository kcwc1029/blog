/*   ch16_9.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int  ch;

    fp = fopen("data9.txt","w");  /* �}�ҥi�g�J�� */ 
    ch = getc(fp);                /* ����Ū����� */ 
    if ( ferror(fp) != 0 )
       printf("Ū�ɥ���\n");
    else
       printf("Ū��OK\n");
    fclose(fp);                   /* �����ɮ� */
    system("pause");
    return 0;
}


