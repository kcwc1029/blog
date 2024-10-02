/*   ch16_10.c                 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *stream;
    char str[] = "DeepMind Co.";

    stream = fopen("out10.txt","w");  /* 開啟可寫入檔 */ 
    fwrite(str, sizeof(str), 1, stream);
    fclose(stream);                   /* 關閉檔案 */
    system("pause");
    return 0;
}


