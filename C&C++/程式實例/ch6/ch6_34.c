/*   ch6_34.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int chicken = 0;
    int rabbit;
    while ( 1 )
    {
    	rabbit = 35 - chicken;		
    	if (2 * chicken + 4 * rabbit == 100)
    	{
    		printf("Âû¦³ %d °¦, ¨ß¦³ %d °¦\n", chicken, rabbit);
    		break;
		}
		chicken++;
	}
    system("pause");
    return 0;
}


