/*   ch5_12.c                  */
int main()
{
    char i;
    printf("A: Access    ......  \n");
    printf("B: Excel     ......  \n");
    printf("C: Word      ......  \n");
    printf("�п�� ==> ");
    scanf("%c",&i);
    printf("\n");
    switch ( i )
    {
    	case 'a':
        case 'A': printf("Access �O��Ʈw�n�� \n");
	        break;
	    case 'b':
        case 'B': printf("Excel �O�պ��n�� \n");
	        break;
	    case 'c':
        case 'C': printf("Word ��ѳB�z�n�� \n");
	        break;
        default:
	        printf("��ܿ��~ \n");
    }
    system("pause");
    return 0;
}


