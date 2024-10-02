/*   ch5_16.c                  */
int main()
{
    char grade;
    
    printf("請輸入成績 : ");
    scanf("%c",&grade);
    printf("\n");
    switch ( grade )
    {
    	case 'a':
        case 'A': 
			printf("Excellent \n");
	        break;
	    case 'b':
        case 'B': 
			printf("Good \n");
	        break;
	    case 'c':
        case 'C': 
			printf("Pass \n");
	        break;
	    case 'd':
	    case 'D': 
			printf("Not good \n");
	    	break;
	    case 'f':
	    case 'F': 
			printf("Fail \n");
	        break; 
        default:
	        printf("輸入錯誤 \n");
    }
    system("pause");
    return 0;
}


