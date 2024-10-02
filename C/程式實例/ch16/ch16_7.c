/*   ch16_7.c                  */
#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE *fp;
    int  i,j,var;

    fp = fopen("data7.txt","r"); /* 開啟檔案 */
    for ( i = 0; i < 5; i++ )
    {
       for ( j = 0; j < 5; j++ )
       {
          fscanf(fp,"%d",&var);
          printf("%c",var);
       }
       printf("\n");
    }
    fclose(fp);  /* 關閉檔案 */
    system("pause");
    return 0;
}





