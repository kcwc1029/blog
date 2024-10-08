/*   ch16_13.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
  	FILE *ptr;
  	char buffer[27];

  	ptr = fopen("out13.txt","rwb");
  	for ( n='A' ; n<='Z' ; n++)
    	fputc(n, ptr);
  	rewind(ptr);
  	fread(buffer, 1, 26, ptr);
  	fclose(ptr);
  	buffer[26]='\0';
  	puts(buffer);
    system("pause");
    return 0;
}




