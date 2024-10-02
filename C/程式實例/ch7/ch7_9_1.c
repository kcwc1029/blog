/*   ch7_9_1.c                   */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int sc[3];

    printf("%X \t %X \t %X\n",&sc[0],&sc[1],&sc[2]);
    printf("%X \t %X \t %X\n",sc,sc+1,sc+2);
    system("pause");
    return 0; 
}


