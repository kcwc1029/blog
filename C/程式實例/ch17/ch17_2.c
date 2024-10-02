/*   ch17_2.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rtn;

    rtn = unlink("data2.txt");
    if (rtn == 0)
    	printf("刪除檔案 OK\n");
    else
    	printf("刪除檔案失敗\n");
    system("pause");
    return 0;  
}



