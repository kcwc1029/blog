/*   ch16_20.c                  */
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  sector;
    int  totalread,totaldigit,totalchar;
    int  i,j;
    char buffer[64];
    char fn[] = "data20.txt";

    fp = fopen(fn,"rb");
    while ( 1 )
    {
       printf("輸入磁區 : ");
       scanf("%d",&sector);
       if ( sector < 0 )
       {
          printf("結束隨機讀取資料 \n");
          break;
       }
       if ( fseek(fp,sector*64,0) != 0 )
       {
          printf("隨機讀取資料錯誤 \n");
          break;
       }
/* 讀取 64 位元組資料如果讀不到這麼多表示已讀到檔案末端 */ 
       if ( ( totalread = fread(buffer,1,64,fp) ) != 64 )
          printf("end of file.... \n");
       totalchar = totaldigit = totalread;
       for ( i = 0; i < ceil((float)totalread / 16); i++ )
       {
          for ( j = 0; j < 16; j++ )
          {
             totaldigit--;
             if ( totaldigit < 0 ) /* 無資料則列空白 */ 
                printf("   ");
             else              /* 否則輸出 16 進位值 */ 
                printf("%3x",buffer[i*16+j]); 
          }
          printf("    "); /* 16 進位值和字元間的空白 */ 
          for ( j = 0; j < 16; j++ )
          {
             totalchar--;
             if ( totalchar < 0 )
                printf(" ");   /* 輸出完成後用空白取代 */ 
             else
                if ( isprint(buffer[i*16+j]) )
                   printf("%c",buffer[i*16+j]);/*輸出字元*/ 
                else           /* 非字元則用 . 取代  */ 
                   printf(".");                 
          }
          printf("\n");
       }
    }
    fclose(fp);
    system("pause");
    return 0;
}




