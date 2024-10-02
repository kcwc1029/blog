/*   ch16_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;

    if ( ( fp = fopen("data1.txt","r") ) == NULL )
       printf("檔案開啟失敗 \n");
    else
       printf("檔案開啟OK \n");
    system("pause");
    return 0;   
}


