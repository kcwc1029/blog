/*   ch14_10.c                   */
#include <stdio.h>
#include <stdlib.h>
typedef  float  temperature;
int main()
{
    temperature  fahrenheit,celsius;

    printf("��J�ؤ�ū� \n==> ");
    scanf("%f",&fahrenheit);
    celsius = ( 5.0 / 9.0 ) * ( fahrenheit - 32.0 );
    printf("��X���ū� %6.2f \n",celsius);
    system("pause");
    return 0;
}


