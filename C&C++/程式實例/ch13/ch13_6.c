/*   ch13_6.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score          	/* 內層結構 */ 
    {
        int   sc;      		/* 分數     */ 
        char  grade;      	/* 成績     */ 
    };
    struct student        	/* 外層結構 */ 
    {
    	char name[12];		/* 名字     */ 
        struct score math;  /* 數學成績 */ 
    } stu = {"洪錦魁",{92, 'A'}};
    
    printf("姓名     ==> %s\n",stu.name);
    printf("數學分數 ==> %d\n",stu.math.sc);
    printf("數學成績 ==> %c\n",stu.math.grade);
    system("pause");
    return 0;
} 


