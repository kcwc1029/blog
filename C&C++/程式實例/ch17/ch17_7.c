/*   ch17_7.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char pathname[80];

    if ( getcwd(pathname,80) == 0 )
    {
       printf("��o�ثe��Ƨ����|���~ \n");
       exit(1);
    }
    printf("�ثe��Ƨ����|�O %s\n",pathname);
    system("pause");
    return 0;
}


