/*   ch5_9.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    printf("�п�J�r�� ==> ");
    ch = getche();
    printf("\n");
    if (( ch >= 'A' ) && ( ch <= 'Z' ))
	   printf("�o�O�j�g�r�� \n");
    else if (( ch >= 'a' ) && ( ch <= 'z' ))
	   printf("�o�O�p�g�r�� \n");
    else if (( ch >= '0' ) && ( ch <= '9' ))
	   printf("�o�O�Ʀr \n");
    else
	   printf("�o�O�S��r�� \n");
    system("pause");
    return 0;
}


