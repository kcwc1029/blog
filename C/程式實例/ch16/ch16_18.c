/*   ch16_18.c                 */
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int fd;
    char fn[] = "out18.bin";
    struct data	  			
    {
      	char name[10];
      	char gender;
      	int age;
   	} info = {"John", 'M', 20};			   
   
   	fd = open(fn, O_CREAT|O_WRONLY|O_BINARY,S_IREAD);
   	if((fd != -1))		/* �˴��O�_�ɮ׶}�Ҧ��\ */
   	{
   		printf("�}�� OK \n");
      	write(fd, &info, sizeof(info));
      	close(fd);
      	printf("�g�J OK \n");
   	}
   	else	
      	printf("�}���ɮץ���\n"); 
   	system("pause");
   	return 0;
}


