/*   ch6_31.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i;
    int count = 1;
    int ans;
    
    srand(time(NULL));
    ans = rand() % 10 + 1; 		/* �]�w���q�Ʀr */
    while ( 1 )
    {
        printf("��J���q�Ʀr : ");
        scanf("%d",&i);
        if ( i > ans )
	        printf("�вq�p�@�I!\n");
	    else if ( i < ans )
		    printf("�вq�j�@�I!\n");
		else    
	        break;
       count++;
    }
    printf("�� %d ���q�� \n",count);
    system("pause");
    return 0;
}


