/*   ch3_10.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch1 = '\a';		
    printf("%c\n", ch1);				  /* 響一聲,沒有其他輸出  */
    printf("ASCII of beep = %d\n", ch1);  /* 印出 ch1 的ASCII值   */
    char ch2 = 7;
    printf("%c\n", ch2);				  /* 響一聲,沒有其他輸出  */
    printf("ASCII of beep = %d\n", ch2);  /* 印出 ch2 的ASCII值   */
    system("pause");
    return 0;
}


