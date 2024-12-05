## Redirecting I/O
- 在命令列應用程式中，輸入通常來自鍵盤（標準輸入），而輸出顯示在螢幕上（標準輸出）。但透過 I/O 重導技術，輸入可以從檔案中讀取，輸出則可以保存至檔案，以下是重導的主要方法與應用：
### 輸入重導 (Input Redirection)
- 標準輸入改為來自檔案：
  - 使用 `<` 將程式輸入來源改為檔案內容。
  - 範例：`$ sum < input`
    - 程式 `sum` 會讀取檔案 `input` 中的數據，而非從鍵盤輸入。
  - 應用場景：讓程式自動處理事先準備好的檔案資料。
  
- 管道 (Piping) 傳遞輸入：
  - 使用 `|` 將一個程式的輸出直接作為另一個程式的輸入。
  - 範例：`$ random | sum`
    - `random` 生成隨機數，直接作為 `sum` 的輸入進行處理。
  - 應用場景：連續處理數據，適合自動化流程。
### 輸出重導 (Output Redirection)
- 將輸出保存至檔案：
  - 使用 `>` 將程式的輸出結果保存至檔案（會覆蓋檔案內容）。
  - 範例：`$ random > out`
    - 將 `random` 程式的輸出數據保存至 `out` 檔案中。
  
- 追加輸出至檔案：
  - 使用 `>>` 將程式的輸出追加至現有檔案的結尾。
  - 範例：`$ random >> out`
    - 新的數據會附加至 `out` 檔案尾部，而不覆蓋原內容。
### 實用案例
1. **批量數據處理：**
   - 用 `<` 將大批量資料文件傳遞給程式處理，避免人工輸入。
   
2. **多步數據傳遞：**
   - 用 `|` 串接多個程式處理數據，例如數據生成與分析。
   
3. **結果保存與追加：**
   - 用 `>` 保存分析結果，或用 `>>` 追加新的計算結果至同一檔案。

## Variable-Length Argument Lists

- 可變參數函數允許接收**不定數量的參數**，適用於需要處理多種類型和數量輸入的情境。
- 範例：printf 函數：
```c
int printf(const char *format, ...);
// `...` 表示可以接受可變數量的參數，並且這些參數可以是不同的數據類型。
```
### <stdarg.h> 提供的功能
![upgit_20241125_1732526072.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241125_1732526072.png)

- **`va_list`**：用來存儲可變參數列表的對象。
- **`va_start`**：初始化 `va_list`，準備提取參數。
```c
va_start(ap, last_fixed_arg);
// ap 是 va_list 對象
// last_fixed_arg 是可變參數列表前最後一個固定參數。
```
- `va_arg`：提取可變參數列表中的參數值。
```c
va_arg(ap, type);
// ap 是 va_list 對象
// type 是要提取的參數類型。
```
- `va_end`：結束可變參數的處理，釋放資源。
```c
va_end(ap);
```
![upgit_20241125_1732526093.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241125_1732526093.png)

![upgit_20241125_1732526112.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241125_1732526112.png)

![upgit_20241125_1732526124.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241125_1732526124.png)

## Using Command-Line Arguments
### 命令列參數的概念
- 命令列參數讓使用者可以在執行程式時直接傳遞資訊，例如選項或檔案名稱。
- 在 `main` 函數中通過以下參數接收命令列輸入：
```c
int main(int argc, char *argv[])
// argc：整數，表示命令列參數的數量。
// argv：字串陣列，存放命令列輸入的參數內容。
```
- argc 的用途：
	- 計算命令列參數的數量，包括程式名稱本身。
	- 範例：執行命令 $ mycopy input output 時，argc = 3。
- argv 的用途：
	- 存放每個參數的字串。
	- 範例：執行命令 $ mycopy input output 時：
		- `argv[0] = "mycopy"`
		- `argv[1] = "input"`
		- `argv[2] = "output"`
![upgit_20241125_1732527726.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241125_1732527726.png)

![upgit_20241125_1732527744.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241125_1732527744.png)

## Notes on Compiling Multiple-Source-File Programs
### 多檔案程式設計的基本概念
- 單一函數定義：函數的定義必須完整地包含在同一檔案內，不能跨檔案分割。
- 分檔設計的目的：
	- 增加程式的模組化、可讀性與重用性。
	- 支援多人協作開發。
### 全域變數的使用
- 全域變數：在任何函數外定義的變數。
- 定義後可供同檔案內的所有函數使用，且可被其他檔案存取。
#### 跨檔案使用全域變數：
- 定義全域變數：在一個檔案中定義全域變數
```c
int flag; // 定義全域變數 flag
```
- 在其他檔案中宣告全域變數：使用 `extern` 關鍵字聲明全域變數
```c
extern int flag; // 宣告 flag 已在其他檔案中定義
// extern 的作用：
// 告知編譯器變數已在其他檔案中定義。
// 編譯器將未解析的引用標記給連結器處理。
```
- 連結器的角色：
	- 若能找到適當的全域變數定義，則完成變數的解析。
	- 若無法找到定義，則報錯並停止生成執行檔。
#### 函數的跨檔案使用：
- 在一個檔案中定義函數：
```c
void myFunction() {
    printf("This is my function.\n");
}
```
- 在其他檔案中宣告函數原型：
```c
void myFunction(); // 宣告函數原型
```
- 使用時需將所有相關檔案一併編譯：
```bash
gcc file1.c file2.c -o myProgram
```
###  範例程式：多檔案開發
- file1.c
```c
#include <stdio.h>
int flag = 1; // 全域變數定義

void myFunction() {
    printf("Flag value: %d\n", flag);
}
```
- file2.c
```c
#include <stdio.h>
extern int flag; // 全域變數宣告
void myFunction(); // 函數原型

int main() {
    myFunction(); // 調用 file1.c 中的函數
    flag = 0;
    myFunction();
    return 0;
}
```
- 編譯與執行：
```bash
gcc file1.c file2.c -o myProgram
./myProgram
```
## Program Termination with exit and atexit
### 程式終止的方式
- 標準方式：從 main 函數返回值，表示程式的執行結果。
- 其他方式：使用 <stdlib.h> 提供的 exit 和 atexit 函數，執行更靈活的程式終止處理。
### exit 函數
- 強制終止程式執行。
- 常用於以下情況：
	- 檢測到輸入錯誤。
	- 無法開啟檔案或其他關鍵資源。
```c
void exit(int status);
// 參數 status：
// EXIT_SUCCESS：表示程式成功終止。
// EXIT_FAILURE：表示程式因錯誤終止。

// 執行行為：
// 清理打開的檔案。
// 執行已註冊的終止處理函數（通過 atexit 註冊）。
// 將狀態碼返回給操作系統。
```

## Suffixes for Integer and Floating-Point Literals(整數與浮點數字面常數後綴)
### 整數字面常數後綴
- **用途**：用於明確指定整數常數的資料型別。
- **後綴類型**：
    - **u 或 U**：無號整數 (unsigned int)。
    - **l 或 L**：長整數 (long int)。
    - **ll 或 LL**：長長整數 (long long int)。
- **範例**：
    - `174u`：無號整數 (unsigned int)。
    - `8358L`：長整數 (long int)。
    - `28373ul`：無號長整數 (unsigned long int)。
    - `9876543210llu`：無號長長整數 (unsigned long long int)。
### 浮點數字面常數後綴
- **用途**：用於明確指定浮點數常數的資料型別。
- **後綴類型**：
    - **f 或 F**：單精度浮點數 (float)。
    - **l 或 L**：長雙精度浮點數 (long double)。
- **範例**：
    - `1.28f`：單精度浮點數 (float)。
    - `3.14159L`：長雙精度浮點數 (long double)。

## Signal Handling
### 信號的概念
- 信號是一種外部異步事件，可能會導致程式異常終止。
- 常見的信號事件：
	- 中斷：例如在 Linux/UNIX 或 Windows 系統中按下 `<Ctrl> + C`。
	- 非法指令：執行不被允許的操作。
	- 記憶體分段錯誤 (Segmentation Violation)：嘗試訪問未分配的記憶體。
	- 浮點運算錯誤：如除以零或運算過大的浮點值。
	- 系統終止命令：由作業系統發出的強制結束。
### 信號處理的功能
- 信號處理 (Signal Handling) 允許程式在發生非預期事件時，進行捕獲與自訂處理，而非直接終止。
- 使用 `<signal.h>` 標頭檔案中的功能來實現。
- 應用：
	- 避免程式因非預期事件直接終止，例如按下 `<Ctrl> + C`。
	- 提供錯誤回報或恢復機制，提高程式的穩定性與用戶體驗。
- 注意事項：
	- 信號處理需謹慎使用，避免影響正常執行邏輯。
	- 某些信號可能無法完全攔截，例如 `SIGKILL` (無條件終止)。
### 信號處理的關鍵函式
#### `signal()` 函式：
- 用於註冊信號處理程序。
- 接收兩個參數：
	 - 信號號碼 (Signal Number)：表示需要處理的信號類型 (例如 `SIGINT`)。
	 - 信號處理函式的指標：指向處理該信號的自訂函式。
#### `raise()` 函式：
- 用於在程式內部產生信號，模擬信號觸發。
- 接收一個信號號碼作為參數。
### 常見信號類型
![upgit_20241126_1732587467.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241126_1732587467.png)
- **`SIGINT`**：中斷信號 (如 `<Ctrl> + C`)，通常用來終止程式執行。
- **`SIGSEGV`**：分段錯誤信號，表示訪問了無效記憶體。
- **`SIGFPE`**：浮點運算錯誤信號，例如除以零。
- **`SIGTERM`**：終止信號，由作業系統或其他程式發出。
### 捕捉 SIGINT 信號
![upgit_20241126_1732587553.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241126_1732587553.png)

![upgit_20241126_1732587566.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241126_1732587566.png)

![upgit_20241126_1732587581.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241126_1732587581.png)

![upgit_20241126_1732587598.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241126_1732587598.png)

1. 註冊信號處理函式：
	- 使用 `signal(SIGINT, signalHandler)` 註冊信號處理程序。
	- 當信號觸發時，控制權轉移至處理函式 `signalHandler`。
2. 信號處理邏輯：
	- 當接收到 `SIGINT` 時，執行自訂訊息提示，並詢問是否繼續執行程式。
	- 如果選擇繼續，需重新初始化信號處理器 (`signal(SIGINT, signalHandler)`)，然後返回程式執行點。
3. 信號模擬：
	- 使用 `raise(SIGINT)` 模擬信號觸發，用於測試信號處理功能。

## Dynamic Memory Allocation: Functions calloc and realloc
### 動態記憶體配置的概念
- 動態記憶體配置允許程式在執行期間根據需求分配或調整記憶體大小。
- 相較於靜態陣列，動態記憶體配置更靈活，可根據程式需求調整記憶體使用。
- 標頭檔案 `<stdlib.h>` 提供兩個主要函式來處理動態記憶體配置：
	- `calloc`：分配並初始化記憶體。
	- `realloc`：調整已分配記憶體的大小。
### 函式 `calloc`
- 用途：為陣列動態分配記憶體並將記憶體初始化為零。
- 特點：分配的記憶體會被初始化為零，與 `malloc` 的區別在於 `malloc` 不初始化記憶體。
```c
void *calloc(size_t nmemb, size_t size);
// 參數
// `nmemb`：需要分配的元素個數。
// `size`：每個元素的大小 (以位元組計算)。

// 返回值
// 成功：返回指向已分配記憶體的指標。
// 失敗：返回 `NULL` 指標。
```
- 範例：
```c
int *array = (int *)calloc(5, sizeof(int)); // 分配 5 個整數的記憶體並初始化為 0
if (array == NULL) {
    // 分配失敗
}
```
#### calloc 使用範例
- 動態分配整數陣列
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int *)calloc(n, sizeof(int)); // 分配 n 個整數，並初始化為 0

    if (arr == NULL) {
        printf("記憶體分配失敗\n");
        return 1;
    }

    // 初始化陣列
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); // 輸出初始化為 0 的值
    }

    free(arr); // 釋放記憶體
    return 0;
}
/*
輸出結果
arr[0] = 0
arr[1] = 0
arr[2] = 0
arr[3] = 0
arr[4] = 0
*/
```
- 動態分配 2D 陣列
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;
    int **matrix = (int **)calloc(rows, sizeof(int *)); // 分配行指標

    if (matrix == NULL) {
        printf("記憶體分配失敗\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int)); // 每行分配列的記憶體
        if (matrix[i] == NULL) {
            printf("記憶體分配失敗\n");
            return 1;
        }
    }

    // 初始化並輸出矩陣
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j; // 初始化
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 釋放記憶體
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
/*
輸出結果
0 1 2 3
1 2 3 4
2 3 4 5
*/
```
### 函式 `realloc`
- 用途：調整已分配記憶體的大小。
- 特點：
    - 當新分配的記憶體比原始記憶體大時，原始內容不會被修改。
    - 當新分配的記憶體比原始記憶體小時，多餘部分會被釋放，但原始內容保持不變。
    - 如果 `size` 為 0，`realloc` 等同於釋放記憶體。
```c
void *realloc(void *ptr, size_t size);
// 參數
// - `ptr`：指向已分配記憶體的指標。如果為 `NULL`，則等同於 `malloc`。
// - `size`：調整後的記憶體大小 (以位元組計算)。

// 返回值
// - 成功：返回指向調整後記憶體的指標。
// - 失敗：返回 `NULL` 指標，原記憶體保持不變。
```
- 範例：
```c
int *array = (int *)malloc(5 * sizeof(int)); // 分配 5 個整數的記憶體
array = (int *)realloc(array, 10 * sizeof(int)); // 調整為 10 個整數的記憶體
if (array == NULL) {
    // 調整失敗
}
```

#### realloc 使用範例
- 動態調整整數陣列大小
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5, new_size = 10;
    int *arr = (int *)malloc(n * sizeof(int)); // 初始化分配大小為 5 的陣列

    if (arr == NULL) {
        printf("記憶體分配失敗\n");
        return 1;
    }

    // 初始化陣列
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // 調整記憶體大小
    arr = (int *)realloc(arr, new_size * sizeof(int));
    if (arr == NULL) {
        printf("記憶體重新分配失敗\n");
        return 1;
    }

    // 初始化新增的部分
    for (int i = n; i < new_size; i++) {
        arr[i] = 0; // 初始化為 0
    }

    // 輸出新陣列
    for (int i = 0; i < new_size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr); // 釋放記憶體
    return 0;
}
/*
輸出結果：
arr[0] = 1
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 5
arr[5] = 0
arr[6] = 0
arr[7] = 0
arr[8] = 0
arr[9] = 0
*/
```
- 動態調整字串大小
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = (char *)malloc(6 * sizeof(char)); // 分配記憶體，存放 "Hello"
    if (str == NULL) {
        printf("記憶體分配失敗\n");
        return 1;
    }

    strcpy(str, "Hello");
    printf("初始字串：%s\n", str);

    // 調整字串大小以容納更多字元
    str = (char *)realloc(str, 12 * sizeof(char)); // 調整大小
    if (str == NULL) {
        printf("記憶體重新分配失敗\n");
        return 1;
    }
    strcat(str, " World"); // 新增內容
    printf("調整後字串：%s\n", str);
    free(str); // 釋放記憶體
    return 0;
}
/*
初始字串：Hello
調整後字串：Hello World
*/
```




### `calloc` 與 `malloc` 的比較

|函式|功能|初始化記憶體|返回值|
|---|---|---|---|
|`malloc`|分配指定大小的記憶體|否|指向記憶體的指標或 `NULL`|
|`calloc`|分配指定大小且初始化為零的記憶體|是|指向記憶體的指標或 `NULL`|
- calloc 和 realloc 綜合範例：動態增加學生分數記錄
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *scores = (int *)calloc(3, sizeof(int)); // 最初存儲 3 名學生的分數
    int count = 3;

    if (scores == NULL) {
        printf("記憶體分配失敗\n");
        return 1;
    }

    // 初始化分數
    for (int i = 0; i < count; i++) {
        scores[i] = 50 + i * 10; // 50, 60, 70
    }

    // 顯示初始分數
    printf("初始分數：\n");
    for (int i = 0; i < count; i++) {
        printf("學生 %d: %d\n", i + 1, scores[i]);
    }

    // 增加記錄容量到 5 名學生
    scores = (int *)realloc(scores, 5 * sizeof(int));
    if (scores == NULL) {
        printf("記憶體重新分配失敗\n");
        return 1;
    }

    // 初始化新增加的學生分數
    for (int i = count; i < 5; i++) {
        scores[i] = 80 + (i - count) * 10; // 80, 90
    }

    // 顯示所有學生分數
    printf("調整後分數：\n");
    for (int i = 0; i < 5; i++) {
        printf("學生 %d: %d\n", i + 1, scores[i]);
    }
    free(scores); // 釋放記憶體
    return 0;
}
/*
輸出結果：
初始分數：
學生 1: 50
學生 2: 60
學生 3: 70
調整後分數：
學生 1: 50
學生 2: 60
學生 3: 70
學生 4: 80
學生 5: 90
*/
```
### 使用動態記憶體配置的注意事項
- 必須手動釋放不再使用的記憶體，否則會導致 **記憶體洩漏 (Memory Leak)**。
```c
free(array);
```
- 在使用 `realloc` 調整記憶體大小時，應注意檢查返回值是否為 `NULL`，以防記憶體調整失敗。