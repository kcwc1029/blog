/*   ch16_12.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *stream;

    stream = fopen("out12.txt","wb");
    fputs("C Programming Book is a good book.", stream);
    fseek(stream, 22, SEEK_SET );
    fputs("By Jiin-Kwei Hung", stream);
    fclose(stream);
    system("pause");
    return 0;
}




