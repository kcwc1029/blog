/*   ch5_18.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ans = 0;
    char num;
    printf("�q�Ʀr�C��,�Фߤ��Q�@�� 0 - 7�������Ʀr, �M��^�����D\n");
	/* �˴�2�i�쪺�� 1 ��O�_�t 1 */
	printf("���S���ݨ�ߤ����Ʀr : \n");
	printf("1, 3, 5, 7 \n");
	printf("��Jy��Y�N��, �䥦�N��L : ");
	scanf(" %c", &num);
	if ((num == 'y') || (num == 'Y')) 
		ans += 1;
	/* �˴�2�i�쪺�� 2 ��O�_�t 1 */
	printf("���S���ݨ�ߤ����Ʀr : \n");
	printf("2, 3, 6, 7 \n");
	printf("��Jy��Y�N��, �䥦�N��L : ");
	scanf(" %c", &num);
	if ((num == 'y') || (num == 'Y')) 
		ans += 2; 
	/* �˴�2�i�쪺�� 3 ��O�_�t 1 */
	printf("���S���ݨ�ߤ����Ʀr : \n");
	printf("4, 5, 6, 7 \n");
	printf("��Jy��Y�N��, �䥦�N��L : ");
	scanf(" %c", &num);
	if ((num == 'y') || (num == 'Y')) 
		ans += 4;
	printf("Ū�̤ߤ��ҷQ���Ʀr�O : %d\n", ans);
    system("pause");
    return 0;
}


