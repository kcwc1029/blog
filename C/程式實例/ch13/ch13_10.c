/*   ch13_10.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, index, max;
    struct family 
    {
    	char title[12];		/* 坝珇嘿     */ 
    	int revenue;		/* 綪扳羆肂   */ 
    } items[3] = {{"Coke",2000},{"獁难",1800},{"ゅㄣ",3200}};
    index = 0;              /* 安砞ま 0 程篫綪 */ 
    max = items->revenue;	/* 安砞ま 0 程篫綪 */
    for (i = 1; i < 3; i++)
	{
		if (max < (items+i)->revenue)
		{
			max = (items+i)->revenue;
			index = i;		/* 穝程篫綪ま    */
		}
	} 
	printf("程篫綪坝珇 : %s\n",(items+index)->title);
	printf("穨罿羆肂 : %d\n", (items+index)->revenue);	   
    system("pause");
    return 0;
} 


