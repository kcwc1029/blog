/*   ch8_19.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char fruit[3][10];
    int i;
    for ( i = 0; i < 3; i++ )
    {
    	printf("�п�J���G : ");
    	scanf("%s",fruit[i]);
	}
	printf("�A��J�����G�p�U : \n");
	for ( i = 0; i < 3; i++ )
	 	printf("%s\n",fruit[i]); 
    system("pause");
    return 0;
}


