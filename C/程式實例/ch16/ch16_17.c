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
	
   	if((src != -1) && (dst != -1))		/* �ˬd�ɮ׬O�_�}�Ҧ��\ */
   	{
      	while( !eof(src) )				
      	{
         	sizeread = read(src, buffer, size);		/* Ū���ɮ� */ 
         	write(dst, buffer, sizeread);	        /* �g�J�ɮ� */	
      	}
      	close(src);	
      	close(dst);
      	printf("�����ɮ� OK\n");
   	}
   	else
      	printf("�}���ɮ� Fail\n");
   	system("pause");
   	return 0;
}


