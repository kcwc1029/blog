/*   ch16_14.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char ch;

    fp = fopen("data14.txt","r");
    while ( (ch = getc(fp)) != EOF )
       putc(ch,stdout);  	/* ¦C¦L¸ê®Æ¨ì¿Ã¹õ */ 
    fclose(fp);
    system("pause");
    return 0;
}



