/*   ch16_22.c                  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp;
    char fn[] = "out22.txt";
    int i;
    int len;
   	char str[100];

   	printf("�п�J�n�[�K���r�� : ");
   	gets(str);
	len = strlen(str);
    for(i = 0; (i < len && str[i] != '\0'); i++)
        str[i] = str[i] + 3; 
    printf("�[�K���G : %s\n", str);     
    fp = fopen(fn,"w");
    fprintf(fp, "%s\n", str);
    fclose(fp);
    system("pause");
    return 0;
}





