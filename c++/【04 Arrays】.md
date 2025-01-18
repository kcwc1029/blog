- 陣列 (Array) 是一種靜態資料結構
- 靜態資料結構的特點是在程式執行期間大小固定不變。
- 陣列是一組連續的記憶體位置，所有元素類型相同。
- 陣列的每個元素可以透過陣列名稱加上索引來存取：`c[0], c[1], c[2]`

## 索引 (Index) 的使用
- 陣列索引（又稱下標）是**整數或整數運算式**。
- 陣列的索引**從 0 開始**：
```cpp
int c[12] = {-45, 6, 0, ..., 62, 78};
printf("%d", c[0] + c[1] + c[2]); // 印出前三個元素的總和
```
###  陣列的括號 (Brackets) 與運算子
- 方括號 ([]) 在 C 中被視為一種運算子，其優先順序與函數呼叫運算子（`()`）相同。
- 方括號運算子用於存取陣列中的元素：
    - 例如：`c[3]` 表示陣列 `c` 的第四個元素。

## Defining Arrays 
- 陣列是以連續記憶體區塊的方式儲存資料。
- 定義陣列時，需要指定元素的資料型別與元素數量，以便電腦預留適當的記憶體空間。
```cpp
int c[12];
// 這段程式碼為整數陣列 `c` 預留 12 個元素，索引範圍為 `0-11`。
```
- 可以在**同一行**定義多個陣列：
```cpp
int b[100], x[27];
```

## Array Examples 
### 定義陣列與初始化
- 未初始化的陣列元素會包含垃圾值`garbage values`。
- 可以使用 `for` 迴圈將陣列初始化為零：
```cpp
int n[5];
for (size_t i = 0; i < 5; i++) {
    n[i] = 0;
}
// size_t 是 C 標準中表示無符號整數的資料型別，適合用於陣列的索引。
```

### 使用初始化列表
- 可以在定義時透過初始化列表設定陣列的初始值：
```cpp
int n[5] = {32, 27, 64, 18, 95};
```
- 若初始化列表中元素少於陣列長度，剩餘元素會自動設為零：
```cpp
int n[10] = {0}; // 初始化所有元素為 0
```
- 若省略陣列大小，則大小會根據初始化列表的元素數量自動決定：
```cpp
int n[] = {1, 2, 3, 4, 5}; // 自動建立 5 個元素的陣列
```
- 使用 `#define` 定義符號常數，方便調整陣列大小：
```cpp
#define SIZE 10
int n[SIZE];
// 修改常數 SIZE 即可動態調整程式，提高可維護性。
```
- 計算陣列元素的總和：使用 for 迴圈累加陣列元素的值：
```cpp
int sum = 0;
for (size_t i = 0; i < 12; i++) {
    sum += a[i];
}
```
```cpp
// 40 位學生對餐廳食物評分（1-10 分）。
int responses[40] = {1, 2, 5, 6, 7, ...};
int frequency[11] = {0};
for (size_t i = 0; i < 40; i++) {
    ++frequency[responses[i]];
}
// C 沒有陣列邊界檢查，若資料超出範圍，可能導致意外行為。
```
```cpp
// 隨機擲骰子的統計：進行 60,000,000 次擲骰子測試，統計 1-6 的出現次數
int frequency[7] = {0};
for (long i = 0; i < 60000000; i++) {
    int face = (rand() % 6) + 1;
    ++frequency[face];
}
```
## Using Character Arrays to Store and Manipulate Strings 
- 在 C 語言中，字串實際上是字元陣列。
- 字串結束符號：所有字串以 null 字元 ('\0') 作為結尾，用於標記字串的終止。
	- `"hello"` 是由個別字元組成的陣列：`{'h', 'e', 'l', 'l', 'o', '\0'}`

### 字元陣列的初始化：
- 使用字串常值 (String Literal) 初始化字元陣列
```cpp
char string1[] = "first";
// 這會自動將字串 "first" 初始化為 {'f', 'i', 'r', 's', 't', '\0'}。
// 陣列大小會由編譯器根據字串長度自動決定，包括 \0 字元。
```
- 使用個別字元常數初始化：
```cpp
char string1[] = {'f', 'i', 'r', 's', 't', '\0'};
// char string1[] = {'f', 'i', 'r', 's', 't', '\0'};
```
![upgit_20241115_1731649631.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731649631.png)

![upgit_20241115_1731649645.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731649645.png)

## Static Local Arrays and Automatic Local Arrays

### 靜態區域變數 (Static Local Variables) 
```cpp
static int arr[5]; // 預設初始化為 {0, 0, 0, 0, 0}
```
- 靜態區域變數在程式執行期間持續存在，但其作用範圍僅限於定義它的函數內部。
- 當將 `static` 用於區域陣列時：
    - 陣列只會初始化一次，且在每次呼叫函數時不會重新建立和銷毀。
    - 適合用於頻繁呼叫的函數，特別是包含大型陣列的情境，可以減少程式執行時間。
### 自動區域變數 (Automatic Local Variables) 的概念
- 自動區域變數的生命週期僅限於函數的執行期間：
	- 每次呼叫函數時，變數會重新建立並初始化。
	- 當函數結束時，變數會自動銷毀。

## Passing Arrays to Functions 
### 傳遞整個陣列 (Passing an Entire Array)
- 在 C 語言中，當將整個陣列傳遞給函數時，不需要使用中括號 []。只需傳遞陣列名稱即可。
- C 自動以引用方式 (pass by reference) 傳遞陣列，這意味著函數會接收到陣列的起始位址，因此可以直接修改原陣列中的元素。
- 陣列名稱實際上是陣列第一個元素的位址，即 `&array[0]`。
```cpp
// 函數宣告：接收一個整數陣列和陣列大小
void modifyArray(int b[], int size);

// 定義陣列並傳遞給函數
int hourlyTemperatures[24];
modifyArray(hourlyTemperatures, 24); 
```
- 顯示陣列的記憶體位址
```cpp
int arr[5] = {1, 2, 3, 4, 5};
printf("Array name: %p\n", arr);
printf("Address of first element: %p\n", &arr[0]);
printf("Address of array: %p\n", &arr);
// arr、&arr[0] 和 &arr 都指向相同的記憶體位址，因為 arr 代表陣列的起始地址。
```
### 傳遞單一陣列元素 (Passing an Individual Array Element)
- 當傳遞單一元素時，使用值傳遞 (pass by value)，這意味著函數只會接收到該元素的複本，不會修改原陣列中的值。
```cpp
// 函數宣告：接收一個整數
void modifyElement(int element);

int a[5] = {10, 20, 30, 40, 50};
modifyElement(a[3]);  // 傳遞單一元素 a[3]
// 在 modifyElement 函數內修改 element 的值，不會影響原陣列 a，因為 element 是值的複本。
```

### 如何修改單一陣列元素 (Using Pointers to Modify an Element)
- 如果希望在函數內修改原陣列的某個元素，可以傳遞指標而不是值：
```cpp
// 函數宣告：接收一個整數指標
void modifyElement(int *element) {
    *element *= 2; // 修改指標指向的變數
}

int a[5] = {10, 20, 30, 40, 50};
modifyElement(&a[3]);  // 傳遞 a[3] 的位址
printf("a[3] after modification: %d\n", a[3]);
// a[3] 的值會被修改，因為傳遞的是該元素的位址，而非值的複本。
```
- 有時候我們不希望函數修改陣列的內容，此時可以使用 const 限制
```cpp
void printArray(const int b[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", b[i]);
    }
}
// const 修飾符確保函數無法修改陣列元素，如果嘗試修改會導致編譯錯誤。
```
## Sorting Arrays：氣泡排序 (Bubble Sort)
![upgit_20241115_1731650918.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731650918.png)

![upgit_20241115_1731650932.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731650932.png)

![upgit_20241115_1731650944.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731650944.png)

## Case Study：Computing Mean, Median and Mode Using Arrays
### 計算平均值 (Mean) 
```c
#include <stdio.h>

double calculateMean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / sizeof(data[0]);

    printf("平均值：%.2f\n", calculateMean(data, size));
    return 0;
}
// 平均值：30.00
```

### 計算中位數 (Median)
```c
#include <stdio.h>

void bubbleSort(int arr[], int size);
double calculateMedian(int arr[], int size);

int main() {
    int data[] = {7, 5, 3, 1, 4};
    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);
    printf("中位數：%.2f\n", calculateMedian(data, size));
    return 0;
}

void bubbleSort(int arr[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

double calculateMedian(int arr[], int size) {
    if (size % 2 != 0) {
        return arr[size / 2];
    } else {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}
// 中位數：4.00
```

## Searching Arrays
### 線性搜尋 (Linear Search) 
```cpp
#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // 返回找到的索引
        }
    }
    return -1; // 若找不到則返回 -1
}

int main() {
    int data[] = {7, 5, 3, 1, 4};
    int key = 3;
    int size = sizeof(data) / sizeof(data[0]);

    int result = linearSearch(data, size, key);
    if (result != -1) {
        printf("找到 %d 在索引 %d\n", key, result);
    } else {
        printf("找不到 %d\n", key);
    }
    return 0;
}
// 找到 3 在索引 2
```

## Multidimensional Arrays
- 多維陣列用於儲存**表格形式的資料**（如行和列）。
- **二維陣列**是最常見的多維陣列，通常用於表示表格 (m x n)。
    - 例如：`int a[3][4];` 表示一個 **3 行 4 列** 的陣列。
    - 每個元素使用兩個索引來存取，例如 `a[i][j]`。
![upgit_20241115_1731652749.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731652749.png)

### 二維陣列初始化
```c
int b[2][2] = {{1, 2}, {3, 4}};
```
- 如果初始值不足，會自動填入 0：
```c
int b[2][2] = {{1}, {3, 4}}; // b[0][1] 會被初始化為 0
```

### 操作二維陣列
- 透過迴圈設定或存取二維陣列元素
```c
for (size_t column = 0; column < 4; ++column) {
    a[2][column] = 0; // 將第 3 行的元素設為 0
}
```
```cpp
// 使用巢狀迴圈計算陣列所有元素的總和：
int total = 0;
for (size_t row = 0; row < 3; ++row) {
    for (size_t column = 0; column < 4; ++column) {
        total += a[row][column];
    }
}
printf("總和: %d\n", total);
```

### 函數接收多維陣列
- 函數接收多維陣列作為參數時，不需要指定第一維的大小，但必須指定其他維度
```cpp
void printArray(const int a[][3], int rows);
// 二維陣列的記憶體配置是按行存儲，這意味著第一行的所有元素會依序存放，接著是第二行。
```






