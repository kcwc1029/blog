/*   ch17_5.c                  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    char subdir[] = "dir5";

    if ( mkdir(subdir) == 0 )
       	printf("建立子資料夾 OK \n");
    else
    	printf("建立子資料夾錯誤 \n");
    system("pause");
    return 0;   
}


