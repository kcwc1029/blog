/*      ch16_13_1.c             */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int x = 5;
    float y = 10.5;
	int z[] = {8, 10, 12, 14, 16};
	FILE *stream;

   	stream = fopen("out13_1.bin","wb"); 	
    fwrite(&x, sizeof(int), 1, stream); 	/* �g�J�ܼ� x */
    fwrite(&y, sizeof(float), 1, stream); 	/* �g�J�ܼ� b */  
    fwrite(z, sizeof(int), 5, stream); 		/* �g�J�}�C z */   
    fclose(stream);	
   	system("pause");
   	return 0;
}


