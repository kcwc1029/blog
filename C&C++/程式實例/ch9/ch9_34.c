/*   ch9_34.c                   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int lottery( )
{
	int n;
    srand(time(NULL));
    n = rand() % 10;
    return n + 1;
}
int main()
{
    int n;

    n = lottery();
    printf("�z�⤤�����O %d\n", n);
    switch (n)
    {
    	case 1:
    		printf("�T���@��\n");
    		break;
    	case 2:
    		printf("60�T�G���q���@�x\n");
    		break;
    	case 3:
    		printf("iPhone 14 �@�x\n");
    		break;
    	case 4:
    		printf("�{���T�U��\n");
    		break;
    	case 5:
    		printf("�{���@�U��\n");
    		break;
    	default:
    		printf("���¥��{\n"); 		
	}
    system("pause");
    return 0;
}


