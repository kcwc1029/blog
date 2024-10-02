/*   ch5_18.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ans = 0;
    char num;
    printf("猜數字遊戲,請心中想一個 0 - 7之間的數字, 然後回答問題\n");
	/* 檢測2進位的第 1 位是否含 1 */
	printf("有沒有看到心中的數字 : \n");
	printf("1, 3, 5, 7 \n");
	printf("輸入y或Y代表有, 其它代表無 : ");
	scanf(" %c", &num);
	if ((num == 'y') || (num == 'Y')) 
		ans += 1;
	/* 檢測2進位的第 2 位是否含 1 */
	printf("有沒有看到心中的數字 : \n");
	printf("2, 3, 6, 7 \n");
	printf("輸入y或Y代表有, 其它代表無 : ");
	scanf(" %c", &num);
	if ((num == 'y') || (num == 'Y')) 
		ans += 2; 
	/* 檢測2進位的第 3 位是否含 1 */
	printf("有沒有看到心中的數字 : \n");
	printf("4, 5, 6, 7 \n");
	printf("輸入y或Y代表有, 其它代表無 : ");
	scanf(" %c", &num);
	if ((num == 'y') || (num == 'Y')) 
		ans += 4;
	printf("讀者心中所想的數字是 : %d\n", ans);
    system("pause");
    return 0;
}


