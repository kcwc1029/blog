/*   ch3_25.c                  */
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int mile, yard;
    float km;

    printf("�N�^���νX���ন����\n");
    printf("�п�J�^�� \n==> ");
    scanf("%d",&mile);
    printf("�п�J�X�� \n==> ");
    scanf("%d",&yard);
    km = 1.609 * ( mile + (float) yard / 1760 );
    printf("���G�O %8.3f \n",km);
    system("pause");
    return 0;
}

