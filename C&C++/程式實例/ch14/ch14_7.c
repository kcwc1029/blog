/*   ch14_7.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    enum WEEK
    {
    	SUN, MON, TUE, WED, THU, FRI, SAT
	} day;
	for (day = SUN; day <= SAT; day++)
    	printf("¦CÁ|¤¸¯À = %d\n",day);
    system("pause");
    return 0;
}



