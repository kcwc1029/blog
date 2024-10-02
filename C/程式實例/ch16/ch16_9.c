/*   ch16_9.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int  ch;

    fp = fopen("data9.txt","w");  /* 開啟可寫入檔 */ 
    ch = getc(fp);                /* 嘗試讀取資料 */ 
    if ( ferror(fp) != 0 )
       printf("讀檔失敗\n");
    else
       printf("讀檔OK\n");
    fclose(fp);                   /* 關閉檔案 */
    system("pause");
    return 0;
}


