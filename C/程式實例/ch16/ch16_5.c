/*   ch16_5.c                  */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  count = 0;

    if ( argc != 2 )
    {
       printf("指令錯誤 ");
       exit(1);
    }
    fp = fopen(argv[1],"r");   /* 開啟檔案   */
    /* 讀到檔案末端才結束 */ 
    while ( getc(fp) != EOF )  
       count++;                /* 計算字元數 */ 
    printf("%s檔案的字元數是 %d\n",argv[1],count);
    fclose(fp);                /* 關閉檔案   */
    system("pause");
    return 0; 
}





