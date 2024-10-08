/*   ch18_6.c                  */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int radix1 = 10;
    int radix2 = 16;
    long value1 = 15677654;
    long value2 = 7445321;
    char str1[80];
    char str2[80];

    ltoa(value1,str1,radix1);
    ltoa(value2,str2,radix2);
    printf("%s \n",str1);
    printf("%s \n",str2);
    system("pause");
    return 0; 
}



