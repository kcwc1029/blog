/*   ch13_17.c                   */
#include <stdio.h>
#include <stdlib.h>
struct TIME
{
	int hours; 		/* �� */
	int mins;		/* �� */	
  	int secs; 		/* �� */  
};
void timeperiod(struct TIME t1, struct TIME t2, struct TIME *diff);
int main()
{
    struct TIME t_start, t_stop, diff;
 
    printf("��J�_�l�ɶ� (�� �� ��) : ");
    scanf("%d %d %d", &t_start.hours, &t_start.mins, &t_start.secs);
    printf("��J�����ɶ� (�� �� ��)�G ");
    scanf("%d %d %d", &t_stop.hours, &t_stop.mins, &t_stop.secs);
    timeperiod(t_start, t_stop, &diff);    /* �I�s�ɶ��t��� */ 
    printf("�ɶ��t�� : %d:%d:%d\n", diff.hours, diff.mins, diff.secs);
 	system("pause");
    return 0;
}
/* �p��ɶ��t */
void timeperiod(struct TIME start, struct TIME stop, struct TIME *diff)
{
    if(start.secs > stop.secs)
	{
		stop.secs += 60;
        --stop.mins;      
    }
    diff->secs = stop.secs - start.secs; 		/* �p���t */ 
    if(start.mins > stop.mins)
	{
		stop.mins += 60;
        --stop.hours;
    }
    diff->mins = stop.mins - start.mins; 		/* �p����t */ 
    diff->hours = stop.hours - start.hours;		/* �p��ɮt */
}



