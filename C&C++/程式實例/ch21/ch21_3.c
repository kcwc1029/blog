/*   ch21_3.c                  */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    char  *str;

    if (( str = (char *) malloc(80*sizeof(char))) == NULL)
    {
       printf("無法取得記憶體空間 \n");
       exit(1);
    }
    printf("請輸入句子 : ");
    gets(str);
    printf("你輸入的句子是 \n");
    puts(str);
    system("pause");
    return 0;
}


