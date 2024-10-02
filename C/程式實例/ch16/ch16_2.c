/*   ch16_2.c                  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    FILE *fp;
    int ret_code;

    if ( ( fp = fopen("ch16_1.c","r") ) == NULL )
    { 
       printf("檔案開啟失敗! \n");
       system("pause");
       exit(1); 
    }
    else
       printf("檔案開啟OK \n");
    if ( (ret_code = fclose(fp))== 0 )
       printf("檔案關閉OK \n");
    system("pause");
    return 0;   
}


