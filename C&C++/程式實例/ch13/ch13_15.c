/*   ch13_15.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct date          	/* ���h���c */ 
    {
        int year;      		/* �X�ͦ~   */	
        int month;			/* �X�ͤ�   */
			int day; 		/* �X�ͤ�   */
	    };
    struct student        	/* �~�h���c */ 
    {
    	char name[12];		/* �W�r     */
		int id; 			/* �Ǹ�     */
		char gender; 		/* �ʧO     */
        struct date birth; 	/* �X�ͤ�䵲�c   */  
    };
	struct student stu[3] = {{"John",20220501,'M',{2001,8,20}},
					 		 {"Kevin",20220502,'M',{2001,3,19}},
					 		 {"Christy",20220503,'F',{2001,5,6}}};
    int i;
    
    for (i = 0; i < 3; i++)
    {
    	printf("�m�W : %s\n",stu[i].name);
    	printf("�Ǹ� : %d\n",stu[i].id);
    	printf("�ʧO : %c\n",stu[i].gender);
    	printf("�X�ͤ�� : %d\\%d\\%d\n",stu[i].birth.year,\
		                                 stu[i].birth.month,\
										 stu[i].birth.day);
		printf("=====\n");	
	} 
    system("pause");
    return 0;
} 


