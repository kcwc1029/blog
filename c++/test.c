#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {  // �T�O����ӼƦr
        printf("�ϥΤ覡: %s �Ʀr1 �Ʀr2\n", argv[0]);
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("�Ʀr1: %d\n", num1);
    printf("�Ʀr2: %d\n", num2);
    printf("�`�M: %d\n", num1 + num2);
    return 0;
}

// ��J
// .\test.exe 10 20

// ��X
// �Ʀr1: 10
// �Ʀr2: 20
// �`�M: 30