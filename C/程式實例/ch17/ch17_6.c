/*   ch17_6.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char subdir[] = "dir5";
    if ( rmdir(subdir) == 0 )
        printf("刪除子資料夾 OK \n");
    else
    	printf("刪除子資料夾錯誤 \n");
    system("pause");
    return 0;   
}



