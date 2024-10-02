/*   ch16_20.c                  */
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    int  sector;
    int  totalread,totaldigit,totalchar;
    int  i,j;
    char buffer[64];
    char fn[] = "data20.txt";

    fp = fopen(fn,"rb");
    while ( 1 )
    {
       printf("��J�ϰ� : ");
       scanf("%d",&sector);
       if ( sector < 0 )
       {
          printf("�����H��Ū����� \n");
          break;
       }
       if ( fseek(fp,sector*64,0) != 0 )
       {
          printf("�H��Ū����ƿ��~ \n");
          break;
       }
/* Ū�� 64 �줸�ո�Ʀp�GŪ����o��h��ܤwŪ���ɮץ��� */ 
       if ( ( totalread = fread(buffer,1,64,fp) ) != 64 )
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
                printf(" ");   /* ��X������Ϊťը��N */ 
             else
                if ( isprint(buffer[i*16+j]) )
                   printf("%c",buffer[i*16+j]);/*��X�r��*/ 
                else           /* �D�r���h�� . ���N  */ 
                   printf(".");                 
          }
          printf("\n");
       }
    }
    fclose(fp);
    system("pause");
    return 0;
}




