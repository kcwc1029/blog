/*   ch8_15.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[] = "Ming-Chi Institute of Technology";
    char str2[] = "Ming-Chi University of Technology";
    int i, cmp;
    int counter = 1;
  
    for ( i = 8; i <= 10; i += 2)
    {
    	printf("�� %d �����\n",counter++);
		printf("����e %d �Ӧ줸��\n", i);
		cmp = strncmp(str1,str2,i);
    	if ( cmp == 0 )
       		printf("�e %d �Ӧr���۵�\n", i);
    	else if ( cmp > 0 )
    	{
       		printf("�e %d �Ӧr�����P\n", i);
       		puts("str1 �r���Ȥj�� str2");
    	}
    	else
    	{
       		printf("�e %d �Ӧr�����P\n", i);
       		puts("str2 �r���Ȥj�� str1");
    	}
    	printf("==========================\n");
	}
    system("pause");
    return 0;
}


