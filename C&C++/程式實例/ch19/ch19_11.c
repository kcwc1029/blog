/*   ch19_11.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct info
    {
    	unsigned int age:7;
    	unsigned int gender:1;
	};
	struct info john = {10, 1};
	struct info mary;
	if (john.gender == 1)
		printf("John是男生, 今年 %d 歲\n",john.age);
	else
		printf("John是女生, 今年 %d 歲\n",john.age);
	mary.age = 20;
	mary.gender = 0;
	if (mary.gender == 1)
		printf("Mary是男生, 今年 %d 歲\n",mary.age);
	else
		printf("Mary是女生, 今年 %d 歲\n",mary.age);
    system("pause");
    return 0;
}


