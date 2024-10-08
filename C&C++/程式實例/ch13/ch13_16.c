/*   ch13_16.c                   */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct POINT
{
  double x;
  double y;
};
double distance(struct POINT, struct POINT);
int main()
{
	double dist;
    struct POINT a = {1, 1};
    struct POINT b = {3, 5};
    dist = distance(a, b);
	printf("distance = %lf\n",dist);
 	system("pause");
    return 0;
}
 
double distance(struct POINT p1, struct POINT p2)
{
    double dist;
    dist = pow(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2),0.5);
    return dist;
}

