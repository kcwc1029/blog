/*   ch16_3.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *fp;
   char ch;	
   
   fp = fopen("out3.txt","w");   
   printf("�п�J��r��ENTER�䵲����J \n");
   while((ch = getche()) != '\r')  
       putc(ch,fp);
   fclose(fp);			/* �����ɮ� */
   system("pause");
   return 0;
}



