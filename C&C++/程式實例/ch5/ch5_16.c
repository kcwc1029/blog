/*   ch5_16.c                  */
int main()
{
    char grade;
    
    printf("�п�J���Z : ");
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
	        printf("��J���~ \n");
    }
    system("pause");
    return 0;
}


