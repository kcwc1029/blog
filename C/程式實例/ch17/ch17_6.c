/*   ch17_6.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char subdir[] = "dir5";
    if ( rmdir(subdir) == 0 )
        printf("�R���l��Ƨ� OK \n");
    else
    	printf("�R���l��Ƨ����~ \n");
    system("pause");
    return 0;   
}



