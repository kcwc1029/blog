/*   ch17_7.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char pathname[80];

    if ( getcwd(pathname,80) == 0 )
    {
       printf("獲得目前資料夾路徑錯誤 \n");
       exit(1);
    }
    printf("目前資料夾路徑是 %s\n",pathname);
    system("pause");
    return 0;
}


