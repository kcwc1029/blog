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
    double d; 					/* 距離 */ 
    
    r = 6371; 					/* 地球半徑         */
	x1 = 22.2838;				/* 香港紅勘車站緯度 */ 
	y1 = 114.1731;				/* 香港紅勘車站經度 */
	x2 = 25.0452;				/* 台北車站緯度     */ 
	y2 = 121.5168;				/* 台北車站經度     */
    
	d = r * acos(sin(x1*2*pi/360)*sin(x2*2*pi/360) + \
	             cos(x1*2*pi/360)*cos(x2*2*pi/360) * \
				 cos((y1-y2)*2*pi/360));
    printf("distance --> %7.2f 公里\n", d);
    system("pause");
    return 0;
}


