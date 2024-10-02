/*   ch17_4.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
int main()
{
	char fn[] = "data4.txt";
    int   fd;
    
    fd = open(fn,O_RDONLY);
    printf("%s 檔案長度是 %d\n",fn,filelength(fd));
    system("pause");
    return 0; 
}


