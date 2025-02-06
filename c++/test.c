#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {  // 絋玂Τㄢ计
        printf("ㄏノよΑ: %s 计1 计2\n", argv[0]);
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("计1: %d\n", num1);
    printf("计2: %d\n", num2);
    printf("羆㎝: %d\n", num1 + num2);
    return 0;
}

// 块
// .\test.exe 10 20

// 块
// 计1: 10
// 计2: 20
// 羆㎝: 30