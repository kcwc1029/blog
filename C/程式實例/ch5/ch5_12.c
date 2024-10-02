/*   ch5_12.c                  */
int main()
{
    char i;
    printf("A: Access    ......  \n");
    printf("B: Excel     ......  \n");
    printf("C: Word      ......  \n");
    printf("請選擇 ==> ");
    scanf("%c",&i);
    printf("\n");
    switch ( i )
    {
    	case 'a':
        case 'A': printf("Access 是資料庫軟體 \n");
	        break;
	    case 'b':
        case 'B': printf("Excel 是試算表軟體 \n");
	        break;
	    case 'c':
        case 'C': printf("Word 文書處理軟體 \n");
	        break;
        default:
	        printf("選擇錯誤 \n");
    }
    system("pause");
    return 0;
}


