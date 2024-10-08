/*   ch16_3.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *fp;
   char ch;	
   
   fp = fopen("out3.txt","w");   
   printf("請輸入文字按ENTER鍵結束輸入 \n");
   while((ch = getche()) != '\r')  
       putc(ch,fp);
   fclose(fp);			/* 關閉檔案 */
   system("pause");
   return 0;
}



