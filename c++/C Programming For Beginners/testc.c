#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pNumber = (int *)malloc(5 * sizeof(int)); // 分配 5 個 int 的空間

    if (pNumber == NULL) {
        printf("記憶體分配失敗！\n");
        return 1;
    }

    // 初始化分配的記憶體
    for (int i = 0; i < 5; i++) {
        pNumber[i] = i + 1;
    }

    // 輸出數值
    for (int i = 0; i < 5; i++) {
        printf("pNumber[%d] = %d\n", i, pNumber[i]);
    }

    free(pNumber); // 釋放記憶體
    return 0;
}
