/*   ch5_5.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int number, rem;

    printf("�п�J���N�� ==> ");
    scanf("%d",&number);
    rem = number % 2;
    if ( rem == 1 )
       printf("%d �O�_�� \n",number);
    else
       printf("%d �O���� \n",number);
    system("pause");
    return 0;   
}


