
## Introduction
- 指標的功能：
	- 模擬傳遞參考：透過指標，可以達到傳遞參考的效果，使函數修改變數值。
	- 函數之間傳遞函數：指標可以用於在函數間傳遞其他函數，以提升程式的彈性。
	- 動態資料結構：透過指標操作，建立和操作執行期間可成長和縮減的資料結構，如鏈結串列、佇列、堆疊與樹。
## Pointer Variable Definitions and Initialization
- 指標是用來儲存記憶體位址的變數。
- 一般變數直接存取數值，而指標則是儲存其他變數的位址。
- 間接參考 (Indirection)：透過指標來存取變數的值。
```c
int count = 10;      // num 儲存數值 10
int *countPtr = &count;   // ptr 儲存 num 的位址
```
![upgit_20241118_1731901281.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731901281.png)
### 指標的宣告與定義
```c
int *countPtr, count;
// countPtr 是 int * 型別，即「指向整數的指標」。
// count 則是 int 型別，不是指標。
```

### 指標的初始化
```c
int *ptr = NULL;  // ptr 指向空位址
// NULL 代表不指向任何記憶體位置，是一種安全的初始值。
```
```c
int num = 25;
int *ptr = &num;  // ptr 指向 num 的位址
printf("num 的值: %d\n", *ptr);  // 輸出: 25
// & 取得變數 num 的位址，*ptr 透過指標取得 num 的值。
```

## Pointer Operators

### 取位址運算子 &
- `&` 是一元運算子，回傳變數的記憶體位址。
```c
int y = 5;
int *yPtr;
yPtr = &y;  // 將 y 的位址賦值給指標 yPtr
```
![upgit_20241118_1731901678.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731901678.png)

### 間接運算子 `*`(Indirection Operator)
- 功能：* 是一元運算子，用於解參考，回傳指標所指向的變數的值。
- 使用 * 的方式稱為解參考 (Dereferencing)。
```c
int y = 5;
int *yPtr = &y;
printf("%d", *yPtr);  // 輸出: 5
// *yPtr 取得 yPtr 所指向的 y 的值，即 5。
```
### 指標運算子 & 和 * 的應用
```c
int a = 10;
int *aPtr = &a;
printf("%d\n", *&a);     // 輸出: 10
printf("%d\n", *aPtr);   // 輸出: 10
printf("%p\n", &a);      // 輸出 a 的記憶體位址
printf("%p\n", aPtr);    // 輸出 aPtr 的值（即 a 的位址）
```
![upgit_20241118_1731903551.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731903551.png)
## Passing Arguments to Functions by Reference

- C 語言中所有參數都是「傳值」：函數呼叫時，會將變數的**副本**傳遞給函數，而不是原變數本身。因此，函數無法直接修改呼叫端的變數。

### Pass-by-Value
![upgit_20241118_1731903993.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731903993.png)

![upgit_20241118_1731904008.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904008.png)

![upgit_20241118_1731904140.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904140.png)

![upgit_20241118_1731904154.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904154.png)

![upgit_20241118_1731904166.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904166.png)


### Pass-by-Reference
- 在呼叫函數時，傳入變數的位址 (&)。
- 函數中使用指標參數接收位址。
- 在函數內透過解參考運算子`*`修改呼叫端變數的值。
![upgit_20241118_1731904035.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904035.png)

![upgit_20241118_1731904098.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904098.png)

![upgit_20241118_1731904212.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904212.png)

![upgit_20241118_1731904226.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731904226.png)


### 陣列作為函數參數的傳遞
- 陣列名稱相當於指向第一個元素的指標 (`&arrayName[0]`)，因此不需要使用 &。
```c
void printArray(int arr[], int size) { // int arr[] 與 int *arr 是等效的。
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4};
    printArray(numbers, 4); // 傳入陣列名稱
    return 0;
}
```
## sizeof Operator
- sizeof 是一元運算子，用來確定各種資料型別或變數在記憶體中的大小（以位元組為單位）。
- 其結果為 size_t 型別，通常為無符號整數。
- sizeof 的結果因編譯器和平台而異，不同系統可能會有不同的位元組數。
- 當用於型別時，記得使用括號（例如 sizeof(int)）。
### sizeof 用於標準資料型別
- sizeof 可用於標準資料型別、變數、或常數，也可用於表達式。
```c
printf("int 型別大小: %zu bytes\n", sizeof(int));   // 輸出: 4 bytes
printf("char 型別大小: %zu bytes\n", sizeof(char)); // 輸出: 1 byte
printf("double 型別大小: %zu bytes\n", sizeof(double)); // 輸出: 8 bytes
```
### sizeof 用於陣列
- 當 sizeof 用於陣列名稱時，回傳的是整個陣列所佔的位元組數。
```c
float array[20]; // 每個 float 佔 4 bytes，共 20 個元素
printf("array 大小: %zu bytes\n", sizeof(array)); // 輸出: 80 bytes
```
- 計算陣列元素個數：
```c
double real[22];
int numElements = sizeof(real) / sizeof(real[0]);
printf("real 的元素個數: %d\n", numElements); // 輸出: 22
```
### 指標與 sizeof
- 當 sizeof 用於指標時，回傳的是指標本身的大小（即記憶體位址所佔的大小）。
```c
int numbers[10];
int *ptr = numbers;
printf("指標大小: %zu bytes\n", sizeof(ptr)); // 輸出: 4 bytes（或 8 bytes，取決於系統）
// sizeof(ptr) 回傳的是指標的大小，而非陣列的大小。
```

## Pointer Expressions and Pointer Arithmetic 
### 加減整數
- 當對指標進行加法或減法時，實際加減的量是整數乘以指向資料型別的大小。
```c
int v[5] = {1, 2, 3, 4, 5};
int *vPtr = v;   // vPtr 指向 v[0]，即記憶體位置 3000（假設）
vPtr += 2;       // vPtr 現在指向 v[2]，位置 3008（因為 int 佔 4 bytes）
```
### 指標相減
- 指標相減僅適用於同一陣列的元素
```c
int *v2Ptr = vPtr + 2; // v2Ptr 指向 v[4]
int diff = v2Ptr - vPtr; // diff = 2（元素數量，而非位元組數）
```
### 指標賦值
- 同類型指標可以相互賦值
```c
int x = 10, y = 20;
int *xPtr = &x;
int *yPtr = &y;
xPtr = yPtr; // xPtr 現在指向 y 的位址
```
### 指標比較
- 指標可使用相等 (`==、!=`) 與關係運算子 (`<, >, <=, >=`) 比較。
- 指標比較僅在相同陣列內有意義
```c
if (vPtr == NULL) {
    printf("指標為 NULL\n");
}
if (vPtr > v2Ptr) {
    printf("vPtr 指向的元素在 v2Ptr 之後\n");
}
```
### 通用指標 `(void *)` 
- `void *` 是一種通用指標，可以指向任何型別的記憶體位址，無論是 `int`、`float` 還是其他資料型別。
- `void *` 無法直接解參考，因為編譯器不知道它實際指向的資料型別。因此，若要存取其內容，必須先進行型別轉換。
```c
// 指派變數位址給 void * 指標
void *ptr;
int num = 5;
ptr = &num; // 將 int 型別位址指派給 void 指標
```
```c
// 從 void * 轉型後解參考
void *ptr;
int num = 5;
ptr = &num;

printf("數值: %d\n", *(int *)ptr); // 需要轉型為 (int *) 才能解參考
```

- 指標運算的應用範例
```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr1 = arr;
    int *ptr2 = arr + 3;

    printf("ptr1 指向的值: %d\n", *ptr1);       // 輸出: 10
    printf("ptr2 指向的值: %d\n", *ptr2);       // 輸出: 40

    ptr1 += 2;  // 移動指標到 arr[2]
    printf("ptr1 現在指向的值: %d\n", *ptr1);  // 輸出: 30

    int diff = ptr2 - ptr1;  // 計算指標間的距離
    printf("ptr2 與 ptr1 之間的元素數量: %d\n", diff); // 輸出: 1

    return 0;
}
```
## Relationship between Pointers and Arrays
- 陣列名稱本質上是常數指標，指向陣列的第一個元素 (&b[0])。
```c
// 將指標指向陣列的第一個元素
int b[5] = {1, 2, 3, 4, 5};
int *bPtr = &b[0]; // 或簡寫為 bPtr = b;

// 指標也可像陣列一樣使用索引
bPtr[1] // 等同於 b[1]
```
- 透過陣列名稱進行指標運算
```c
*(b + 3) // 等同於 b[3]
```
## Arrays of Pointers(字串陣列)
- 在 C 語言中，字串本質上是字元指標，即指向字串首字元的記憶體位址。
- 字串陣列是一種指標陣列，其中**每個元素都是指向字串的指標**。
```c
const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
// suit[4]：表示陣列有 4 個元素。
// char *：表示每個元素是指向 char 的指標。
```
- 字串陣列的記憶體配置：
	- 雖然看起來字串被存放在 suit 陣列中，但實際上存放的是指向字串的指標。
	- 陣列本身是固定大小（4 個元素），但每個元素指向的字串可以是任意長度。
![upgit_20241118_1731905627.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241118_1731905627.png)


## Pointers to Functions
- 函數指標是指向函數位址的指標。
- 就像陣列名稱是指向陣列首元素的位址，函數名稱是指向函數起始位址。
- 函數指標的用途：
	- 可以傳遞給其他函數作為參數。
	- 可以從函數中回傳。
	- 可以存入陣列，用於實現選單系統。
	- 可以賦值給其他函數指標變數。
### 使用函數指標的範例：泡沫排序 (Bubble Sort)
#### 函數定義：
```c
int (*compare)(int a, int b);
// `compare` 是指向函數的指標，該函數接受兩個 `int` 參數並回傳 `int`。
```
#### 函數指標的使用:
```c
if ((*compare)(work[count], work[count + 1]))
```
#### 完整程式碼
```c
#include <stdio.h>

void bubbleSort(int work[], int size, int (*compare)(int, int));
int ascending(int a, int b);
int descending(int a, int b);
void swap(int *a, int *b);

int main() {
    int array[] = {34, 12, 4, 56, 17};
    int size = sizeof(array) / sizeof(array[0]);
    int order;

    printf("選擇排序方式 (1 = 升冪, 2 = 降冪): ");
    scanf("%d", &order);

    if (order == 1) {
        bubbleSort(array, size, ascending);
    } else {
        bubbleSort(array, size, descending);
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void bubbleSort(int work[], int size, int (*compare)(int, int)) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1; i++) {
            if ((*compare)(work[i], work[i + 1])) {
                swap(&work[i], &work[i + 1]);
            }
        }
    }
}

int ascending(int a, int b) {
    return a > b;
}

int descending(int a, int b) {
    return a < b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### 選單系統程式碼範例
```c
#include <stdio.h>

void function1(int num);
void function2(int num);
void function3(int num);

int main() {
    void (*f[3])(int) = {function1, function2, function3};
    int choice;

    printf("輸入 0, 1 或 2 選擇函數: ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < 3) {
        (*f[choice])(choice); // 呼叫對應的函數
    } else {
        printf("無效選擇\n");
    }

    return 0;
}

void function1(int num) {
    printf("執行 function1，輸入值為: %d\n", num);
}

void function2(int num) {
    printf("執行 function2，輸入值為: %d\n", num);
}

void function3(int num) {
    printf("執行 function3，輸入值為: %d\n", num);
}
```














