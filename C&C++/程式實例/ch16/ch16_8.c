/*   ch16_8.c                  */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  count = 0;
    int  ch;

    if ( argc != 2 )
    {
       printf("���O���~ ");
       exit(1);
    }
    fp = fopen(argv[1],"r");   /* �}���ɮ�   */
    /* Ū���ɮץ��ݤ~���� */ 
    while ( !feof(fp) )
    {
       ch = getc(fp);  
       count++;                /* �p��r���� */
    }    
    printf("%s�ɮת��r���ƬO %d\n",argv[1],count);
    fclose(fp);                /* �����ɮ�   */
    system("pause");
    return 0; 
}





