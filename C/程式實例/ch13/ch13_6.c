/*   ch13_6.c                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct score          	/* ���h���c */ 
    {
        int   sc;      		/* ����     */ 
        char  grade;      	/* ���Z     */ 
    };
    struct student        	/* �~�h���c */ 
    {
    	char name[12];		/* �W�r     */ 
        struct score math;  /* �ƾǦ��Z */ 
    } stu = {"�x�A��",{92, 'A'}};
    
    printf("�m�W     ==> %s\n",stu.name);
    printf("�ƾǤ��� ==> %d\n",stu.math.sc);
    printf("�ƾǦ��Z ==> %c\n",stu.math.grade);
    system("pause");
    return 0;
} 


