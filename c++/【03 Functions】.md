## Modularizing Programs in C
- **模組化程式設計**：
	- 使用函數來模組化程式，提升可讀性與重用性。
	- 程式碼集中定義，調用時只需一次撰寫，且與其他函數隔離。
- **C 標準函數庫**提供豐富的預定義函數，用於：
	- 數學計算 (如 `pow`)
	- 字串操作
	- 字元操作
	- 輸入/輸出 (如 `printf`, `scanf`)
- 使用自定義函數：由程式設計師定義的函數，可在程式的多個地方重複使用。
### 函數的層級結構
![upgit_20241114_1731559930.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731559930.png)
- 主函數（如老闆）調用子函數（如員工）完成任務。
- 隱藏實作細節：主函數不需要知道子函數的實作過程，只需調用即可。
- 層級式調用：子函數可再調用其他子函數，`worker1` 同時是 `worker4` 和 `worker5` 的主函數。

## Math Library Functions
- **數學函數**可用於執行常見的數學計算。
- 算 900 的平方根：`printf("%.2f", sqrt(900.0)); // 輸出 30.00`
![upgit_20241114_1731560121.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731560121.png)

![upgit_20241114_1731560139.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731560139.png)


## Functions
### 函式的作用
- 函式可將程式模組化，提升程式的可讀性與維護性。
- 程式中的變數若在函式內定義，即為**區域變數**，只能在該函式內部存取。
- 函式通常會有參數，用於在不同函式間傳遞資料，參數也屬於區域變數。
- 封裝與模組化：將程式碼包裝成函式，可以在程式的不同位置重複使用，只需透過呼叫該函式即可執行。 
### 函式化程式碼的動機
- 分而治之：將複雜問題拆解為小問題，便於開發。
- 軟體重用性：使用現有的函式作為**建構模塊**，減少重複程式碼。
- 重用性也是**物件導向程式設計**的核心，例如 C++、Java、C# 等語言。
- 抽象化：如使用標準庫的 `printf`、`scanf`、`pow` 等函式。
- 避免重複：將重複的程式碼封裝成函式，減少維護成本。
### 函數的基本結構
```c
return-type function-name(parameter-list) {
    // 函數主體：包含定義與敘述
}
- return-type：函數回傳的資料型態。
- function-name：函數名稱。
- parameter-list：參數列表，如無參數則為 `void`。

範例：`int square(int y)`：此函數接收一個整數參數，並回傳該數的平方。
```
### 函數的宣告、呼叫與定義
- 函數宣告 (prototype)：在使用前告知編譯器函數的名稱與參數型態。
- 函數呼叫：在 `main()` 函數或其他函數中使用。
- 函數定義：實作函數的邏輯。
```c
// 宣告
int square(int y);

// 定義
 int square(int y) {
  return y * y;
}

// 呼叫
printf("%d", square(5)); // 呼叫函數 square 計算 5 的平方
```
### `main()` 的回傳值
- `main()` 函數的預設回傳值為 `int`，表示程式執行是否成功。
- `return 0;` 代表程式執行成功。


- 函數範例：計算平方
```c
int square(int y); // 函數宣告

int main(void) {
    for (int x = 1; x <= 10; ++x) {
        printf("%d ", square(x)); // 呼叫函數
    }
    return 0;
}

int square(int y) {
    return y * y; // 回傳平方值
}
```
- 函數範例：找出三數中的最大值
```c
int maximum(int x, int y, int z);

int main(void) {
    int num1, num2, num3;
    printf("輸入三個整數: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    printf("最大值為: %d\n", maximum(num1, num2, num3));
    return 0;
}

int maximum(int x, int y, int z) {
    int max = x;
    if (y > max) max = y;
    if (z > max) max = z;
    return max;
}
```
## Function Prototypes
- 函數原型是 C++ 引入 C 的功能，編譯器透過它來檢查函數呼叫是否正確。
- 早期 C 語言無法檢查函數呼叫，容易導致執行時錯誤或難以偵測的邏輯錯誤。
- 範例：
```c
int maximum(int x, int y, int z);
// 表示 `maximum` 接受三個 `int` 型別參數並回傳 `int` 型別的結果。
```
- 如果函數呼叫與原型不匹配，會產生編譯錯誤。
- 若函數原型與函數定義的回傳類型不一致，也會導致錯誤。
- 例：若原型為 `void maximum(int x, int y, int z);` 而定義為 `int maximum(int x, int y, int z);`，則編譯器會報錯。
### 引數強制轉型 (Argument Coercion)
- 函數原型會自動強制轉型引數至適當型別。
	- 例：`sqrt(4)` 會自動將整數 `4` 轉為 `double` 類型 `4.0`。
	- `printf("%.3f\n", sqrt(4));` 會正確輸出 `2.000`。
- 若資料型別不對應，則會根據 C 的數值轉換規則進行轉換。
	- 如 `double` 轉為 `int` 會截去小數部分 (例：`square(4.5)` 回傳 `16` 而非 `20.25`)。

#### 混合型別運算的數值轉換規則
- 若表達式中含有多種資料型別，編譯器會自動將低型別轉換為高型別，且不改變原值

| 整數規則                                              | 浮點數規則                                |
| ------------------------------------------------- | ------------------------------------ |
| 低型別整數 (如 `short`) 通常會提升為高型別整數 (如 `int` 或 `long`)。 | 若有 `long double`，其他轉為 `long double`。 |
|                                                   | 若有 `double`，其他轉為 `double`。           |
|                                                   | 若有 `float`，其他轉為 `float`。             |

- 如果需要將高型別轉換為低型別，需要使用顯式轉型 (cast)：
```c
int x = (int) 4.7; // x 會變成 4
```
## Function Call Stack and Stack Frames
### 堆疊 (Stack) 的概念
- 堆疊 (Stack) 是一種資料結構，類似疊盤子：
	- 推入 (Push)：將資料放入堆疊頂部。
	- 彈出 (Pop)：從堆疊頂部取出資料。
- 堆疊遵循後進先出 (LIFO) 原則。
### 函數呼叫堆疊 (Function Call Stack)
- 函數呼叫堆疊是支援函數呼叫與返回的重要結構：
	- 管理函數的回傳地址，確保函數在執行完畢後返回正確的位置。
	- 管理自動變數 (Automatic Variables)，確保變數在函數執行時存在，結束後釋放記憶體。
### 堆疊框架 (Stack Frame)
- 每次函數呼叫時，會在堆疊中推入一個堆疊框架 (Stack Frame)：
	- 包含**回傳地址**及函數的自動變數空間。
- 當函數完成後，堆疊框架會被彈出，釋放其記憶體。
### 自動變數的管理
- 自動變數只在函數執行期間存在，函數結束後會被釋放。
- 當堆疊框架彈出時，對應的自動變數會自動失效。
### 堆疊溢位 (Stack Overflow)
- 電腦記憶體有限，堆疊空間也是有限的。
- **過多的函數呼叫**可能導致**堆疊溢位** (Stack Overflow) 錯誤。

### 範例：堆疊操作 (以 `square` 函數為例)
1. 作業系統先呼叫 `main` 函數，將 `main` 的堆疊框架推入堆疊：
   - `main` 的堆疊框架包含回傳地址 R1 和自動變數空間。
2. `main` 呼叫 `square` 函數，推入 `square` 的堆疊框架：
   - `square` 的堆疊框架包含回傳地址 R2 和自動變數空間。
3. `square` 計算完成後，堆疊框架彈出，返回 `main`。
4. `main` 繼續執行，最後返回作業系統，釋放其堆疊框架。

![upgit_20241114_1731561553.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731561553.png)

![upgit_20241114_1731561571.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731561571.png)

![upgit_20241114_1731561599.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731561599.png)

![upgit_20241114_1731561619.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731561619.png)


## Headers
### C語言的標頭檔
- 每個標準函式庫都有相應的標頭檔，內含所有函式的函式原型以及各種資料型態與常數的定義。
- 範例：`#include <stdio.h>` 引入標準輸入/輸出函式庫。
- 標頭檔主要用於函式原型驗證，確保函式呼叫的參數與回傳型態正確，避免編譯錯誤。
- 使用標頭檔有助於程式的重用性和可維護性。
### 自訂標頭檔
- 可以建立自己的標頭檔(.h檔案)來定義函式原型，方便模組化管理程式碼。
- 範例：如果 `square` 函式的原型在 `square.h`，可使用：`#include "square.h"`
![upgit_20241114_1731561874.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731561874.png)

![upgit_20241114_1731561889.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241114_1731561889.png)


## Random Number Generation 
- 使用 `<stdlib.h>` 中的 `rand()` 函數來生成整數亂數，範圍為 `0` 到 `RAND_MAX` (最小值為 32767)。
- 產生的數值是**偽隨機數**，即每次執行時序列相同，但通過 `srand()` 可改變序列。
- 範例：使用 `%` 餘數運算符進行縮放 (scaling)，將 `rand()` 限制在 `0-5` 範圍內，再加 `1` 使其範圍變為 `1-6`
```c
int face = 1 + rand() % 6;
```
- 隨機數種子 (Seed)：
	- 預設行為：每次執行 `rand()` 生成的序列相同，便於程式除錯。
	- 隨機化序列：使用 `srand()` 配合 `time()` 生成不同的亂數序列：
```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 使用時間作為隨機數種子
    srand(time(NULL)); // `time(NULL)` 回傳自 1970 年 1 月 1 日以來的秒數作為種子。
    // 模擬擲骰子 10 次
    for (int i = 0; i < 10; i++) {
        // 生成 1 到 6 的隨機數
        int dice = 1 + rand() % 6;
        printf("第 %d 次擲骰子結果: %d\n", i + 1, dice);
    }
    return 0;
}
/*
第 1 次擲骰子結果: 4
第 2 次擲骰子結果: 1
第 3 次擲骰子結果: 6
第 4 次擲骰子結果: 2
第 5 次擲骰子結果: 5
第 6 次擲骰子結果: 3
第 7 次擲骰子結果: 4
第 8 次擲骰子結果: 2
第 9 次擲骰子結果: 6
第 10 次擲骰子結果: 1
*/
```
## Storage Classes 
- 變數的屬性包括：名稱、類型、大小和數值。
- C 語言中的標識符還具有storage class、storage duration、scope跟linkage。
### 自動儲存類別 (Automatic Storage Duration)：auto
- 預設用於函數內的區域變數。
- 變數僅在所屬的區塊內有效（區域範疇）。
- 區域變數在區塊進入時建立，離開時銷毀。
### 靜態儲存類別 (Static Storage Duration)：static
- `static int count = 0;`
- 變數在**程式執行期間持續存在**。
- 只在定義的函數內可見，但在**多次函數呼叫間保留其值**。
### 全域變數 (Global Variables)：extern（可省略）
- **宣告在任何函數之外**，整個程式執行期間都存在。
- 任何後續函數都可存取（全域範疇）。
- 用於在多檔案專案中**共享變數**。
### 寄存器變數 (Register Variables)：register
- 請求將變數儲存在CPU 寄存器中，以提高存取速度。
- 通常用於需要頻繁存取的變數。
- 不能取得變數的記憶體地址（無法使用 `&` 取址）。
```cpp
// 【範例】Storage Classes
#include <stdio.h>

void countFunction() {
    static int count = 0; // 靜態區域變數
    count++;
    printf("Count: %d\n", count);
}

int main() {
    for (int i = 0; i < 3; i++) {
        countFunction(); // 呼叫多次函數時，count 保留先前的值
    }
    return 0;
}
// Count: 1
// Count: 2
// Count: 3
```

## Scope Rules 
- Scope是指識別符號（如變數、函數）的可見區域。
- Scope在其定義的範圍內可被引用，但在範圍外則無法使用。

### 識別符號的範圍 (Scope of Identifiers)

- 函數範圍 (Function Scope)：
	- 標籤僅能在定義的函數內使用，用於 goto 和 switch 語句中。
- 檔案範圍 (File Scope)：
	- 定義在所有函數外的識別符號具有檔案範圍。
	- 這些識別符號從定義點開始，在整個檔案內部有效（如全域變數和函數）。
- 區塊範圍 (Block Scope)：
	- 定義在區塊 {} 內的變數。
	- 區塊結束後，變數的作用範圍終止。
	- 區塊中的靜態變數 (static) 具有區塊範圍，但其儲存期間延續至程式結束。
- 函數原型範圍 (Function-Prototype Scope)：
	- 參數列表中的識別符號僅在函數原型內部有效。
	- 函數原型只需要參數的類型，名稱是可選的，且會被編譯器忽略。
![upgit_20241115_1731644800.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731644800.png)

![upgit_20241115_1731644812.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731644812.png)

![upgit_20241115_1731644823.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731644823.png)

![upgit_20241115_1731644832.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731644832.png)

## Recursion
- 遞迴是函數**直接或間接呼叫自身**來解決問題的技巧。
### 遞迴的基本結構：
- 基礎情況 (Base Case)：函數能解決最簡單的情況，遇到基礎情況時直接回傳結果，結束遞迴。
- 遞迴步驟 (Recursive Step)：當問題較複雜時，將其分成兩部分：
	- 函數知道如何解決的部分。
	- 函數不完全知道如何解決，但可以轉化為更簡單的同類問題，再呼叫自身處理。
- 遞迴運作過程：
	- 函數呼叫自己來處理更小版本的原問題，每次呼叫自身時，問題會變得更簡單。
	- 原始函數會暫停執行，直到遞迴步驟完成，然後逐步回傳結果。
- 遞迴終止條件：
	- 每次呼叫函數時，問題必須逐漸接近基礎情況，否則遞迴將無法終止（導致無限遞迴）。

### 範例：階層(Factorial)
- 階乘 `n!` 表示從 `n` 乘到 `1` 的乘積：`5! = 5 × 4 × 3 × 2 × 1 = 120`
- 特殊情況：
	- `0! = 1`
	- `1! = 1`
```cpp
// 使用 for 迴圈計算階乘（非遞迴方式）：
factorial = 1;
for (counter = number; counter >= 1; counter--) {
    factorial *= counter;
}
```
- 使用遞迴計算階乘
![upgit_20241115_1731645282.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731645282.png)

![upgit_20241115_1731645294.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731645294.png)


- 運作過程：
- 當呼叫 `factorial(5)` 時，函數會不斷呼叫自己直到遇到 `factorial(1)`。
- 執行順序：
    - `factorial(5)` → `factorial(4)` → `factorial(3)` → `factorial(2)` → `factorial(1)`
- 當達到基礎情況 (`1!`)，遞迴停止，開始**回傳結果**：
    - `factorial(1) = 1`
    - `factorial(2) = 2 × factorial(1) = 2`
    - `factorial(3) = 3 × factorial(2) = 6`
    - `factorial(4) = 4 × factorial(3) = 24`
    - `factorial(5) = 5 × factorial(4) = 120`
![upgit_20241115_1731645248.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731645248.png)

### 範例：費氏數列 (Fibonacci Series) 
- 費氏數列的前兩個數為 0 和 1，之後的每一個數是**前兩個數之和**。
- 範例：0, 1, 1, 2, 3, 5, 8, 13, 21, …
```cpp
// 數學公式：
fibonacci(0) = 0
fibonacci(1) = 1
fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)
```
- 遞迴方式計算費氏數列的函數
![upgit_20241115_1731645695.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731645695.png)

![upgit_20241115_1731645706.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731645706.png)

- 函數執行過程：
	- 基礎情況：當 `n == 0` 或 `n == 1` 時，直接回傳 `n`。
	- 遞迴步驟：當 `n > 1` 時，函數會呼叫自己兩次：`fibonacci(n - 1)` 和 `fibonacci(n - 2)`
![upgit_20241115_1731645645.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731645645.png)


## Recursion vs. Iteration
- 迴圈 (Iteration)：透過重複語句 (`for` 或 `while` loop) 來執行任務。
- 遞迴 (Recursion)：透過函數呼叫自身來重複執行任務。
    - 迴圈使用重複語句來進行操作，而遞迴使用選擇語句（如 `if`）來進行基礎情況判斷。
### 共同點
- 重複執行：兩者都涉及重複處理問題。
    - 迴圈：使用重複語句反覆執行，直到條件不成立為止。
    - 遞迴：透過重複的函數呼叫，直到達到基礎情況為止。
- 終止測試：
    - 迴圈：當迴圈條件為 `false` 時終止。
    - 遞迴：當達到基礎情況時終止。
### 步接近終止
- 迴圈：通常透過修改計數器逐步接近終止條件。
- 遞迴：透過每次呼叫減少問題的規模，逐步接近基礎情況。
- 無窮迴圈與無窮遞迴：
    - 無窮迴圈：當迴圈條件永遠不為 `false`。
    - 無窮遞迴：當遞迴步驟無法有效縮小問題範圍而無法達到基礎情況。****

### 遞迴的缺點
- 效能問題：
	- 每次遞迴呼叫都會消耗處理器時間和記憶體空間。
	- 每次遞迴呼叫會建立函數的新副本（僅限於變數部分），可能會大量消耗記憶體。
- 迴圈的優勢：
	- 迴圈通常在函數內執行，不需要反覆的函數呼叫，因此不會有額外的呼叫成本和記憶體分配。

### 遞迴與迴圈的比較總結
![upgit_20241115_1731645913.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/11/upgit_20241115_1731645913.png)














