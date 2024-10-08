/*   ch17_3.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rtn;
    char src[] = "data3.txt";
    char dst[] = "out3.txt";

    rtn = rename(src, dst);    
    if (rtn == 0)
    	printf("更改名稱 OK\n");
    else
    	printf("更改名稱失敗\n");
    system("pause");
    return 0;  
}


