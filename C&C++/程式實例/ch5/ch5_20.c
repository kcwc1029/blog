/*   ch5_20.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float v;
    
	printf("�п�J���b�t�� : ");
	scanf("%f", &v);
	if (v < 7.9)
        printf("�A�H�y�ìP�L�k�i�J�Ӫ�\n");
    else if (v == 7.9)
        printf("�H�y�ìP�i�H��¶�a�y�@��β���\n");
    else if ((v > 7.9) && (v < 11.2))
        printf("�H�y�ìP�i�H��¶�a�y�@���β���\n");
    else if ((v >= 11.2) && (v < 16.7))
        printf("�H�y�ìP�i�H��¶�Ӷ�����\n");
    else 
        printf("�H�y�ìP�i�H�����Ӷ��t\n");
    system("pause");
    return 0;
}


