/*   ch3_26.c                  */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z;

    x = y = z = 0;
/* 測試 ++ 運算子 */
    x = ++y + ++z;
    printf("第 11 列結果 %d %d %d\n",x,y,z);
    x = y++ + z++;
    printf("第 13 列結果 %d %d %d\n",x,y,z);
/* 測試 -- 運算子 */
    x = y = z = 0;
    x = --y + --z;
    printf("第 17 列結果 %d %d %d\n",x,y,z);
    x = y-- + z--;
    printf("第 19 列結果 %d %d %d\n",x,y,z);
    system("pause");
    return 0;
}
