/*   ch14_13.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    enum Machine 
	{
		running=1, maintenance, failed	
	} state;
    
    printf("請輸入機器生產狀態 \n");
    printf("1. 生產中\n");
    printf("2. 維修中\n");
    printf("3. 損壞\n= ");
	scanf("%d",&state); 
    switch (state)
    {
        case running:
        	printf("機器正常生產中\n");
            break;
        case maintenance :
        	printf("機器正常維修中\n");
            break;
        case failed :
        	printf("機器損壞\n");
            break;    
        default: 
        	printf("輸入錯誤\n");
          	break;
    }
    system("pause");
    return 0;
}


