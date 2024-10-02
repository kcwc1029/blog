/*   ch9_34.c                   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int lottery( )
{
	int n;
    srand(time(NULL));
    n = rand() % 10;
    return n + 1;
}
int main()
{
    int n;

    n = lottery();
    printf("您抽中獎號是 %d\n", n);
    switch (n)
    {
    	case 1:
    		printf("汽車一輛\n");
    		break;
    	case 2:
    		printf("60吋液晶電視一台\n");
    		break;
    	case 3:
    		printf("iPhone 14 一台\n");
    		break;
    	case 4:
    		printf("現金三萬元\n");
    		break;
    	case 5:
    		printf("現金一萬元\n");
    		break;
    	default:
    		printf("謝謝光臨\n"); 		
	}
    system("pause");
    return 0;
}


