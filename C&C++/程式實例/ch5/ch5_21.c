/*   ch5_21.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int main()
{
    int market_x = 40;			/* ��P�����^�奭�����Z */ 
    int market_y = 80; 			/* ��P�������|�������Z */
    int editor_x = 80; 			/* �s�賡���^�奭�����Z */ 
    int editor_y = 60; 			/* �s�賡�����|�������Z */ 
    int employ_x = 60;			/* �s�i�H���^��Ҹզ��Z */
    int employ_y = 55; 			/* �s�i�H�����|�Ҹզ��Z */ 
    float m_dist, e_dist; 		/* ��P�Z��, �s��Z��   */ 
    m_dist = pow(pow(market_x-employ_x,2)+pow(market_y-employ_y,2),0.5);
    e_dist = pow(pow(editor_x-employ_x,2)+pow(editor_y-employ_y,2),0.5);
    printf("�s�i�H���P�s�賡���t�� %5.2f\n",e_dist);
    printf("�s�i�H���P��P�����t�� %5.2f\n",m_dist);
    if (m_dist > e_dist)
    	printf("�s�i�H������A�X�s�賡��\n");
    else
    	printf("�s�i�H������A�X�s�賡��\n");
    system("pause");
    return 0;
}


