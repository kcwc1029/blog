/*   ch17_2.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rtn;

    rtn = unlink("data2.txt");
    if (rtn == 0)
    	printf("�R���ɮ� OK\n");
    else
    	printf("�R���ɮץ���\n");
    system("pause");
    return 0;  
}



