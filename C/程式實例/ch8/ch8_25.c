/*   ch8_25.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char course[][50] = {"AI 數學",
					     "Python",
					     "現代物理"};					
    int len;
	len = sizeof(course) / sizeof(course[0]);
	printf("字串數量 = %d\n", len);
    system("pause");
    return 0;
}


