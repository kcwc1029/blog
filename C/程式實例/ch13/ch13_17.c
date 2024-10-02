/*   ch13_17.c                   */
#include <stdio.h>
#include <stdlib.h>
struct TIME
{
	int hours; 		/* 時 */
	int mins;		/* 分 */	
  	int secs; 		/* 秒 */  
};
void timeperiod(struct TIME t1, struct TIME t2, struct TIME *diff);
int main()
{
    struct TIME t_start, t_stop, diff;
 
    printf("輸入起始時間 (時 分 秒) : ");
    scanf("%d %d %d", &t_start.hours, &t_start.mins, &t_start.secs);
    printf("輸入結束時間 (時 分 秒)： ");
    scanf("%d %d %d", &t_stop.hours, &t_stop.mins, &t_stop.secs);
    timeperiod(t_start, t_stop, &diff);    /* 呼叫時間差函數 */ 
    printf("時間差值 : %d:%d:%d\n", diff.hours, diff.mins, diff.secs);
 	system("pause");
    return 0;
}
/* 計算時間差 */
void timeperiod(struct TIME start, struct TIME stop, struct TIME *diff)
{
    if(start.secs > stop.secs)
	{
		stop.secs += 60;
        --stop.mins;      
    }
    diff->secs = stop.secs - start.secs; 		/* 計算秒差 */ 
    if(start.mins > stop.mins)
	{
		stop.mins += 60;
        --stop.hours;
    }
    diff->mins = stop.mins - start.mins; 		/* 計算分差 */ 
    diff->hours = stop.hours - start.hours;		/* 計算時差 */
}



