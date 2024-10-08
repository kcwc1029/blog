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
    	printf("第 %d 次比較\n",counter++);
		printf("比較前 %d 個位元組\n", i);
		cmp = strncmp(str1,str2,i);
    	if ( cmp == 0 )
       		printf("前 %d 個字元相等\n", i);
    	else if ( cmp > 0 )
    	{
       		printf("前 %d 個字元不同\n", i);
       		puts("str1 字元值大於 str2");
    	}
    	else
    	{
       		printf("前 %d 個字元不同\n", i);
       		puts("str2 字元值大於 str1");
    	}
    	printf("==========================\n");
	}
    system("pause");
    return 0;
}


