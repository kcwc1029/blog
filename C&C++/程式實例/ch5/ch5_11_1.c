/*   ch5_11_1.c                  */
int main()
{
    int i;
    printf("1. Access    ......  \n");
    printf("2. Excel     ......  \n");
    printf("3. Word      ......  \n");
    printf("請選擇 ==> ");
    scanf("%d",&i);
    printf("\n");
    switch ( i )
    {
       case 1: 
	   		printf("Access 是資料庫軟體 \n");
	       	break;
       case 2:
	   		printf("Excel 是試算表軟體 \n");
	        break;
       case 3: 
	   		printf("Word 文書處理軟體 \n");
	        break;
       default:
	       	printf("選擇錯誤 \n");
    }
    system("pause");
    return 0;
}


