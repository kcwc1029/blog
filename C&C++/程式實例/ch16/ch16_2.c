/*   ch16_2.c                  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    FILE *fp;
    int ret_code;

    if ( ( fp = fopen("ch16_1.c","r") ) == NULL )
    { 
       printf("�ɮ׶}�ҥ���! \n");
       system("pause");
       exit(1); 
    }
    else
       printf("�ɮ׶}��OK \n");
    if ( (ret_code = fclose(fp))== 0 )
       printf("�ɮ�����OK \n");
    system("pause");
    return 0;   
}


