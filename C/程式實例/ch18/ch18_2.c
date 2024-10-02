/*   ch18_2.c                  */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int  value;
    char *str1 = "123";
    char *str2 = "123tre";
    char *str3 = "r541";

    value = atoi(str1);
    printf("%d \n",value);
    value = atoi(str2);
    printf("%d \n",value);
    value = atoi(str3);
    printf("%d \n",value);
    system("pause");
    return 0;
}


