/*    ch8_4_1.c                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char name1[] = "Hung"; 	 
    char name2[] = {'H','u','n','g'};
    printf("��X�r��     : %s\n", name1);
	printf("��X�r���}�C : %s\n", name2); 
	printf("�r  ��  �� %d �Ӧ줸��\n", sizeof(name1));
	printf("�r���}�C�� %d �Ӧ줸��\n", sizeof(name2));
    system("pause");
    return 0; 
}


