/*   ch11_30.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *ptr = "Ming Chi";
				
    puts(ptr);
    puts(ptr+5);
    printf("%s\n",ptr);
    printf("%s\n",ptr+5);
    printf("²¾°Ê ptr «á\n");
	ptr += 5;
	puts(ptr);
	printf("%s\n",ptr); 	 	 
    system("pause");
    return 0;
}


