/*   ch16_21.c                 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main(int argc, char *argv[])
{
    long pos;
    int  fd;
    int  sector;
    int  totalread,totaldigit,totalchar;
    int  i,j;
    char buffer[64];
    char fn[] = "data20.txt";

    fd = open(fn,O_RDONLY | O_BINARY);
    while ( 1 )
    {
       printf("��J�ϰ� : ");
       scanf("%d",&sector);
       if ( sector < 0 )
       {
          printf("�����H��Ū����� \n");
          break;
       }
       pos = (long) sector * 64;
       if ( lseek(fd,pos,SEEK_SET) == -1 )
       {
          printf("�H��Ū����ƿ��~ \n");
          break;
       }
/* Ū�� 64 �줸�ո�Ʀp�GŪ����o��h��ܤwŪ���ɮץ��� */       
       if ( ( totalread = read(fd,buffer,64) ) != 64 )
          printf("end of file.... \n");
       totalchar = totaldigit = totalread;
       for ( i = 0; i < ceil((float)totalread / 16); i++ )
       {
          for ( j = 0; j < 16; j++ )
          {
             totaldigit--;
             if ( totaldigit < 0 ) /* �L��ƫh�C�ť� */
                printf("   ");
             else              /* �_�h��X 16 �i��� */
                printf("%3x",buffer[i*16+j]);
          }
          printf("    "); /* 16 �i��ȩM�r�������ť� */
          for ( j = 0; j < 16; j++ )
          {
             totalchar--;
             if ( totalchar < 0 )
                printf(" "); /* ��X������Ϊťը��N */
             else
                if ( isprint(buffer[i*16+j]) )
                   printf("%c",buffer[i*16+j]);/*��X�r��*/
                else         /* �D�r���h�� . ���N  */
                   printf(".");
          }
          printf("\n");
       }
    }
    close(fd);
    system("pause");
    return 0;
}


