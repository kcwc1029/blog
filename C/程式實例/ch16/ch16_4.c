/*   ch16_4.c                  */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if ( argc != 2 )
    {
       printf("«ü¥O¿ù»~ ");
       exit(1);
    }
    fp = fopen(argv[1],"r");
    while ( (ch = getc(fp)) != EOF )
       printf("%c",ch);
    fclose(fp);
    system("pause");
    return 0;
}





