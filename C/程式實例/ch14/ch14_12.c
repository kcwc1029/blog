/*   ch14_12.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    enum week { SUN, MON, TUE, WED, THR, FRI, SAT };
    enum week day;
    int  total, pay, hour;

    total = 0;
    printf("請輸入週日至週六的工作時數 \n");
    for ( day = SUN; day <= SAT; day++ )
    {
       scanf("%d",&hour);
       switch ( day )
       {
          case SUN : pay = hour * 200; /* 週日 */ 
                     break;
          case SAT : pay = hour * 180; /* 週六 */ 
                     break;
          default  : pay = hour * 160;  /* 週一至週五 */
                     break;
       }
       total += pay;
    }
    printf("週薪是 : %d\n",total);
    system("pause");
    return 0;
}


