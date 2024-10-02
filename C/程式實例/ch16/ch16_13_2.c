/*      ch16_13_2.c             */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int x;
    float y;
	int z[5];
	FILE *stream;
	int i;

   	stream = fopen("out13_1.bin","rb"); 	
    fread(&x, sizeof(int), 1, stream); 		/* 讀取變數 x */
    fread(&y, sizeof(float), 1, stream); 	/* 讀取變數 b */  
    fread(z, sizeof(int), 5, stream); 		/* 讀取陣列 z */   
    fclose(stream);	
    printf("x = %d\n", x);
    printf("y = %f\n", y);
    for (i = 0; i < 5; i++)
    	printf("z[%d] = %d\n", i, z[i]);
   	system("pause");
   	return 0;
}


