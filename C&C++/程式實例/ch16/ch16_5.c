/*   ch16_5.c                  */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  count = 0;

    if ( argc != 2 )
    {
       printf("���O���~ ");
       exit(1);
    }
    fp = fopen(argv[1],"r");   /* �}���ɮ�   */
    /* Ū���ɮץ��ݤ~���� */ 
    while ( getc(fp) != EOF )  
       count++;                /* �p��r���� */ 
    printf("%s�ɮת��r���ƬO %d\n",argv[1],count);
    fclose(fp);                /* �����ɮ�   */
    system("pause");
    return 0; 
}





