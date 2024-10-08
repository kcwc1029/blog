/*   ch16_11.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *stream;
    char var;

    stream = fopen("out10.txt","rb");
    /* 若不是讀到檔案末端則繼續讀 */ 
    while ( fread(&var,sizeof(var),1,stream) != 0 )
       printf("%c",var);
	printf("\n"); 
    fclose(stream);
    system("pause");
    return 0;
}




