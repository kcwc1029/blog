/*   ch16_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;

    if ( ( fp = fopen("data1.txt","r") ) == NULL )
       printf("�ɮ׶}�ҥ��� \n");
    else
       printf("�ɮ׶}��OK \n");
    system("pause");
    return 0;   
}


