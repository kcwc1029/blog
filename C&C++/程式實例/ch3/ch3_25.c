/*   ch3_25.c                  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int mile, yard;
    float km;

    printf("將英哩及碼數轉成公里\n");
    printf("請輸入英哩 \n==> ");
    scanf("%d",&mile);
    printf("請輸入碼數 \n==> ");
    scanf("%d",&yard);
    km = 1.609 * ( mile + (float) yard / 1760 );
    printf("結果是 %8.3f \n",km);
    system("pause");
    return 0;
}

