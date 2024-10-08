/*   ch4_16.c                               */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double r; 
    double x1, y1;
    double x2, y2;
    double pi = 3.1415926;
    double d; 					/* �Z�� */ 
    
    r = 6371; 					/* �a�y�b�|         */
	x1 = 22.2838;				/* ������ɨ����n�� */ 
	y1 = 114.1731;				/* ������ɨ����g�� */
	x2 = 25.0452;				/* �x�_�����n��     */ 
	y2 = 121.5168;				/* �x�_�����g��     */
    
	d = r * acos(sin(x1*2*pi/360)*sin(x2*2*pi/360) + \
	             cos(x1*2*pi/360)*cos(x2*2*pi/360) * \
				 cos((y1-y2)*2*pi/360));
    printf("distance --> %7.2f ����\n", d);
    system("pause");
    return 0;
}


