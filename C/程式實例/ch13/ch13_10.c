/*   ch13_10.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, index, max;
    struct family 
    {
    	char title[12];		/* �ӫ~�W��     */ 
    	int revenue;		/* �P���`���B   */ 
    } items[3] = {{"Coke",2000},{"�w��",1800},{"���",3200}};
    index = 0;              /* ���]���� 0 �̺Z�P */ 
    max = items->revenue;	/* ���]���� 0 �̺Z�P */
    for (i = 1; i < 3; i++)
	{
		if (max < (items+i)->revenue)
		{
			max = (items+i)->revenue;
			index = i;		/* ��s�̺Z�P����    */
		}
	} 
	printf("�̺Z�P�ӫ~ : %s\n",(items+index)->title);
	printf("�~�Z�`���B : %d\n", (items+index)->revenue);	   
    system("pause");
    return 0;
} 


