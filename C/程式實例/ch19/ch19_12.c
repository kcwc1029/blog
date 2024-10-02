/*   ch19_12.c                 */
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
	int sex, ages;
	printf("請輸入年齡 : ");
	scanf("%d",&ages);
	john.age = ages;
	printf("請輸入性別 : ");
	scanf("%d",&sex);
	john.gender = sex;
	struct info mary;
	if (john.gender == 1)
		printf("John是男生, 今年 %d 歲\n",john.age);
	else
		printf("John是女生, 今年 %d 歲\n",john.age);
    system("pause");
    return 0;
}


