/*   ch16_17.c                 */
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#define  size    512
int main()
{
    char buffer[size];
   	char fin[] = "data17.txt";
   	char fout[] = "out17.txt";
   	int src, dst;
	int sizeread;

   	src = open(fin, O_RDONLY|O_TEXT);
   	dst = creat(fout, S_IWRITE);
	
   	if((src != -1) && (dst != -1))		/* 檢查檔案是否開啟成功 */
   	{
      	while( !eof(src) )				
      	{
         	sizeread = read(src, buffer, size);		/* 讀取檔案 */ 
         	write(dst, buffer, sizeread);	        /* 寫入檔案 */	
      	}
      	close(src);	
      	close(dst);
      	printf("拷貝檔案 OK\n");
   	}
   	else
      	printf("開啟檔案 Fail\n");
   	system("pause");
   	return 0;
}


