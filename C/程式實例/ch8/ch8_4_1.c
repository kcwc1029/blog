/*    ch8_4_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name1[] = "Hung"; 	 
    char name2[] = {'H','u','n','g'};
    printf("輸出字串     : %s\n", name1);
	printf("輸出字元陣列 : %s\n", name2); 
	printf("字  串  佔 %d 個位元組\n", sizeof(name1));
	printf("字元陣列佔 %d 個位元組\n", sizeof(name2));
    system("pause");
    return 0; 
}


