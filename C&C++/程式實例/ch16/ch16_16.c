/*   ch16_16.c                 */
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#define  size    512
int main()
{
    int  fd;                  /* �ɮץN�� */
    char buf[size];
    int  count = 0;
    int  i;
    char fn[] = "data16.txt";
    
    fd = open(fn ,O_RDONLY);
    while ( ( i = read(fd,buf,size) ) > 0 )
       count += i;
    printf("%s ���r���ƬO %d\n", fn, count);
    close(fd);
    system("pause");
    return 0;
}


