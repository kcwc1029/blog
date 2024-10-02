/*   ch16_15.c                 */
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int  fd;                  /* 檔案代號 */

    if ( (fd = open("data15.txt",O_RDONLY)) == -1 )
    {
       printf("開檔失敗 \n");
       exit(1);
    }
    else
       printf("開檔 OK \n");

    if ( close(fd) == -1 )
       printf("關檔失敗 \n");
    else
       printf("關檔 OK \n");
    system("pause");
    return 0;   
}



