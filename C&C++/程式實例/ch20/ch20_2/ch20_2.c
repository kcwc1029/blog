/*    ch20_2.c                 */
#include <stdio.h>
#include <stdlib.h>
int add(int, int);
int sub(int, int);
int mul(int, int);
int main()
{ 
    printf("2 + 5 = %d\n",add(2,5));
    printf("9 - 3 = %d\n",sub(9,3));
    printf("3 * 6 = %d\n",mul(3,6));
	system("pause");
    return 0;
}

