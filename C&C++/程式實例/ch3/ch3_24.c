/*   ch3_24.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sc;
    char grade[10];
    
    printf("請輸入你的 C 語言成績 \n==>");
    scanf("%d", &sc);
    printf("你的 C 語言成績是 %d \n", sc);
    printf("請讀取成績等級 \n");
    scanf("%s", grade);
    printf("你的 C 語言等級是 %s \n", grade);
    
    system("pause");
    return 0;
}


