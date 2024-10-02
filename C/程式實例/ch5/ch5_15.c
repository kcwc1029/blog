/*   ch5_15.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int year, rem4, rem100, rem400;

    printf("請輸入測試年份 ==> ");
    scanf("%d",&year);
    rem400 = year % 400;
    rem100 = year % 100;
    rem4 = year % 4;
    if ((( rem4 == 0 ) && ( rem100 != 0 )) || ( rem400 == 0 ))
       printf("%d 是閏年 \n", year);
    else
       printf("%d 不是閏年 \n", year);
    system("pause");
    return 0;   
}


