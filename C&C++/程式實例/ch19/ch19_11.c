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
		printf("John¬O¨k¥Í, ¤µ¦~ %d ·³\n",john.age);
	else
		printf("John¬O¤k¥Í, ¤µ¦~ %d ·³\n",john.age);
	mary.age = 20;
	mary.gender = 0;
	if (mary.gender == 1)
		printf("Mary¬O¨k¥Í, ¤µ¦~ %d ·³\n",mary.age);
	else
		printf("Mary¬O¤k¥Í, ¤µ¦~ %d ·³\n",mary.age);
    system("pause");
    return 0;
}


