/*   ch5_8.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sc;
    printf("請輸入分數 : ");
    scanf("%d", &sc);
    if (sc >= 90)
    	printf(" A \n");
	else if (sc >= 80)
	    printf(" B \n");
	else if (sc >= 70)
	    printf(" C \n");
	else if (sc >= 60)
	    printf(" D \n");
	else
	    printf(" F \n");    
    system("pause");
    return 0;
}


