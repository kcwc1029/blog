/*   ch11_24_1.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int num[3];

    printf("%X \t %X \t %X\n",&num[0],&num[1],&num[2]);
    printf("%X \t %X \t %X\n",num,num+1,num+2);
    system("pause");
    return 0; 
}


