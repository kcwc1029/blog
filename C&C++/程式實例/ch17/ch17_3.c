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
    	printf("���W�� OK\n");
    else
    	printf("���W�٥���\n");
    system("pause");
    return 0;  
}


