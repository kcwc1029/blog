/*   ch9_23_1.c                   */
#include <stdio.h>
#include <stdlib.h>
int val;              /* �ŧi�����ܼ� */ 
void max(int a, int b)
{
    val = ( a > b ) ? a : b;
}
int main()
{
    int c = 5;
    int d = 6;

    max( c, d );
    printf("���j�� = %d \n",val);
    system("pause");
    return 0;
}


