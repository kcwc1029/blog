/*   ch5_11_1.c                  */
int main()
{
    int i;
    printf("1. Access    ......  \n");
    printf("2. Excel     ......  \n");
    printf("3. Word      ......  \n");
    printf("�п�� ==> ");
    scanf("%d",&i);
    printf("\n");
    switch ( i )
    {
       case 1: 
	   		printf("Access �O��Ʈw�n�� \n");
	       	break;
       case 2:
	   		printf("Excel �O�պ��n�� \n");
	        break;
       case 3: 
	   		printf("Word ��ѳB�z�n�� \n");
	        break;
       default:
	       	printf("��ܿ��~ \n");
    }
    system("pause");
    return 0;
}


