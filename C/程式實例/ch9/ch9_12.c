/*   ch9_12.c                   */
#include <stdio.h>
#include <stdlib.h>
char grade(int sc)
{
	char rtn;
	if (sc >= 90)
		rtn = 'A';
	else if (sc >= 80)
		rtn = 'B';
	else if (sc >= 70)
		rtn = 'C';
	else if (sc >= 60)
		rtn = 'D';
	else 
		rtn = 'F';
	return rtn; 
}
int main()
{
	int score;

    printf("輸入 0 則程式結束!\n"); 
    while ( 1 )
    {
    	printf("請輸入分數 : ");
    	scanf("%d",&score);
    	printf("最後成績是 = %c\n", grade(score));
    	printf("----------\n");
    	if (score == 0)
    		break;
	}
    system("pause");
    return 0;
}


