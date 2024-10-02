/*   ch14_10.c                   */
#include <stdio.h>
#include <stdlib.h>
typedef  float  temperature;
int main()
{
    temperature  fahrenheit,celsius;

    printf("輸入華氏溫度 \n==> ");
    scanf("%f",&fahrenheit);
    celsius = ( 5.0 / 9.0 ) * ( fahrenheit - 32.0 );
    printf("輸出攝氏溫度 %6.2f \n",celsius);
    system("pause");
    return 0;
}


