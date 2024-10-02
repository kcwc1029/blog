/*   ch5_7.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch;
    int ages;

    printf("你是否要駕照 ?(y/n) ");
    ch = getche();
    printf("\n");
    
    if ( ch == 'y' )
    {
       printf("你幾歲 ? ");
       scanf("%d",&ages);
       if ( ages < 18 )
	      printf("對不起你年齡太小 \n");
       else
	      printf("你需要考駕照 \n");
    }
    system("pause");
    return 0;
}


