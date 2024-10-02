/*   ch13_5.c                   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    } stu;
    strcpy(stu.name,"洪錦魁");
    stu.math.sc = 92;
    stu.math.grade = 'A';
    printf("姓名     ==> %s\n",stu.name);
    printf("數學分數 ==> %d\n",stu.math.sc);
    printf("數學成績 ==> %c\n",stu.math.grade);
    system("pause");
    return 0;
} 


