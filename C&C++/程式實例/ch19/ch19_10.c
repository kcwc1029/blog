/*   ch19_10.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct info
    {
    	unsigned int age:7;
    	unsigned int gender:1;
	};
	struct info john;
	printf("john所佔的位元組數 = %d\n",sizeof(john));
    system("pause");
    return 0;
}


