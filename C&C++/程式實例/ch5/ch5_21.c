/*   ch5_21.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int main()
{
    int market_x = 40;			/* 行銷部門英文平均成績 */ 
    int market_y = 80; 			/* 行銷部門社會平均成績 */
    int editor_x = 80; 			/* 編輯部門英文平均成績 */ 
    int editor_y = 60; 			/* 編輯部門社會平均成績 */ 
    int employ_x = 60;			/* 新進人員英文考試成績 */
    int employ_y = 55; 			/* 新進人員社會考試成績 */ 
    float m_dist, e_dist; 		/* 行銷距離, 編輯距離   */ 
    m_dist = pow(pow(market_x-employ_x,2)+pow(market_y-employ_y,2),0.5);
    e_dist = pow(pow(editor_x-employ_x,2)+pow(editor_y-employ_y,2),0.5);
    printf("新進人員與編輯部門差異 %5.2f\n",e_dist);
    printf("新進人員與行銷部門差異 %5.2f\n",m_dist);
    if (m_dist > e_dist)
    	printf("新進人員比較適合編輯部門\n");
    else
    	printf("新進人員比較適合編輯部門\n");
    system("pause");
    return 0;
}


