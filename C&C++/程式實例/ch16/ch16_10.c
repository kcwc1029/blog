/*   ch16_10.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *stream;
    char str[] = "DeepMind Co.";

    stream = fopen("out10.txt","w");  /* �}�ҥi�g�J�� */ 
    fwrite(str, sizeof(str), 1, stream);
    fclose(stream);                   /* �����ɮ� */
    system("pause");
    return 0;
}


