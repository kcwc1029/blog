/*   ch16_15.c                 */
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int  fd;                  /* �ɮץN�� */

    if ( (fd = open("data15.txt",O_RDONLY)) == -1 )
    {
       printf("�}�ɥ��� \n");
       exit(1);
    }
    else
       printf("�}�� OK \n");

    if ( close(fd) == -1 )
       printf("���ɥ��� \n");
    else
       printf("���� OK \n");
    system("pause");
    return 0;   
}



