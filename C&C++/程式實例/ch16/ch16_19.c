/*   ch16_19.c                 */
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
    fd = open(fn, O_RDONLY|O_BINARY);  
    if((fd != -1))		/* �˴��O�_�ɮ׶}�Ҧ��\ */
    {
       	read(fd, &info, sizeof(info)); 
       	printf("info.name   = %s\n",info.name); 
       	printf("info.gender = %c\n",info.gender);
       	printf("info.age    = %d\n",info.age); 
       	close(fd);
    }
    else	
       	printf("�}���ɮץ���\n");
   	system("pause");
   	return 0;
}


