/*   ch17_5.c                  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    char subdir[] = "dir5";

    if ( mkdir(subdir) == 0 )
       	printf("�إߤl��Ƨ� OK \n");
    else
    	printf("�إߤl��Ƨ����~ \n");
    system("pause");
    return 0;   
}


