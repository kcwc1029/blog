/*   ch5_22.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int month;
    
    printf("�п�J��� : ");
    scanf("%d", &month);
    switch (month)
    {
    	case 2: printf("%d ����� 28 ��\n", month);
    		break;
    	case 1:
    	case 3:
    	case 5:
    	case 7:
    	case 8:
    	case 10:
    	case 12: printf("%d ����� 31 ��\n", month);
    		break;
    	case 4:
    	case 6:
    	case 9:
    	case 11: printf("%d ����� 30 ��\n", month);
    		break;
    	default:
    		printf("�����J���~\n");
	}
    system("pause");
    return 0;
}


