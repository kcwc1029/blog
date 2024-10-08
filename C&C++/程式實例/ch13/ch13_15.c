/*   ch13_15.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct date          	/* 內層結構 */ 
    {
        int year;      		/* 出生年   */	
        int month;			/* 出生月   */
			int day; 		/* 出生日   */
	    };
    struct student        	/* 外層結構 */ 
    {
    	char name[12];		/* 名字     */
		int id; 			/* 學號     */
		char gender; 		/* 性別     */
        struct date birth; 	/* 出生日其結構   */  
    };
	struct student stu[3] = {{"John",20220501,'M',{2001,8,20}},
					 		 {"Kevin",20220502,'M',{2001,3,19}},
					 		 {"Christy",20220503,'F',{2001,5,6}}};
    int i;
    
    for (i = 0; i < 3; i++)
    {
    	printf("姓名 : %s\n",stu[i].name);
    	printf("學號 : %d\n",stu[i].id);
    	printf("性別 : %c\n",stu[i].gender);
    	printf("出生日期 : %d\\%d\\%d\n",stu[i].birth.year,\
		                                 stu[i].birth.month,\
										 stu[i].birth.day);
		printf("=====\n");	
	} 
    system("pause");
    return 0;
} 


