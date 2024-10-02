/*   ch5_5.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int number, rem;

    printf("請輸入任意值 ==> ");
    scanf("%d",&number);
    rem = number % 2;
    if ( rem == 1 )
       printf("%d 是奇數 \n",number);
    else
       printf("%d 是偶數 \n",number);
    system("pause");
    return 0;   
}


