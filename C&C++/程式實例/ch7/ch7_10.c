/*   ch7_10.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, mymax;
    int arr[5] = {76, 32, 88, 45, 65};
    
    for ( i = 0; i < 5; i++ )
    {
    	if (i == 0)
    		mymax = arr[i];
    	else
    		if (mymax < arr[i])
				mymax = arr[i];	
	}		
	printf("³Ì¤j­È = %d\n", mymax);
    system("pause");
    return 0;
}


