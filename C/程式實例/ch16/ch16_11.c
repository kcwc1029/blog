/*   ch16_11.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *stream;
    char var;

    stream = fopen("out10.txt","rb");
    /* �Y���OŪ���ɮץ��ݫh�~��Ū */ 
    while ( fread(&var,sizeof(var),1,stream) != 0 )
       printf("%c",var);
	printf("\n"); 
    fclose(stream);
    system("pause");
    return 0;
}




