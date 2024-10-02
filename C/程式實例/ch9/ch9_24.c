/*   ch9_24.c                   */
#include <stdio.h>
#include <stdlib.h>
void varfunction()
{
    int var = 0;
    static int static_var = 0;

    printf("var = %d \n",var);
    printf("ÀRºA static static_var = %d \n",static_var);
    var++;
    static_var++;
}
int main()
{
    int  i;

    for ( i = 0; i < 3; i++ )
       varfunction();
    system("pause");
    return 0;
}


